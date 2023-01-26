#!/bin/bash

# Architecture
echo '# Architecture:    ' $(uname -a)

# CPU
read socket_count cpu_count < <(lscpu --parse=socket,cpu | awk -F ',' -v socket=-1 '
! /^#/ {
    if (socket != $1) {
        socket_count++
        socket = $1
    }
    cpu_count++
}
END {
    print socket_count,cpu_count
}')
echo '# CPU Physical:    ' $socket_count
echo '# vCPU:            ' $cpu_count
echo '# CPU Usage:       ' $(mpstat | awk '$3=="all" { printf "%.2f%%", 100 - $13 }')

# Memory and Disk
echo '# Memory Usage:    ' $(free --mega | awk '
/^Mem/ {
    printf "%d / %d (%.2f%%)", $3, $2, 100 * $3 / $2
}' | numfmt --from-unit=1M --to=si --field=1,3)

echo '# Disk Usage:      ' $(df --block-size=MB --output=used,size | awk '
NR > 1 {
    used += $1
    size += $2
}
END {
    printf "%d / %d (%.2f%%)", used, size, 100 * used / size
}' | numfmt --from-unit=1M --to=si --field=1,3)

if [[ $(/usr/sbin/lvm lvscan | grep 'ACTIVE') ]]
then
    lvm_use="Yes"
else
    lvm_use="No"
fi
echo '# LVM Use:         ' $lvm_use

# Who
echo '# User Log:        ' $(who --users | wc -l)
echo '# Last Boot:       ' $(who --boot | awk '{ print $3,$4 }')

# Network
echo '# Network IP:      ' $(hostname -I | awk '{ print $1 }')
echo '# TCP Connections: ' $(ss --tcp --no-header | wc -l) 'ESTABLISHED'

# Sudo
echo '# Sudo:            ' $(journalctl _COMM=sudo | grep COMMAND | wc -l)
