BEGIN { FS="=" }

/^GRUB_INIT_TUNE/ {
	gsub(/"/, "", $2);
	system("./grub_init_tune_tester.sh "$2)
}

