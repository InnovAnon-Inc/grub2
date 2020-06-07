#! /usr/bin/env bash
set -exu

    grep -vq  '^blacklist pcspkr$/'    /etc/modprobe.d/blacklist.conf ||
sudo sed -i 's/^blacklist pcspkr$/#&/' /etc/modprobe.d/blacklist.conf
sudo modprobe pcspkr
./theme.awk < grub

