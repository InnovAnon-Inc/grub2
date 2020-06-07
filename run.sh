#! /usr/bin/env bash
set -exu
(( ! $# ))

     grep -vq '^blacklist pcspkr$/'    /etc/modprobe.d/blacklist.conf ||
sudo sed -i 's/^blacklist pcspkr$/#&/' /etc/modprobe.d/blacklist.conf
sudo modprobe pcspkr

cd "$(dirname "$(readlink -f "$0")")"
./theme.awk < grub

