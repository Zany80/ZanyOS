all:
	cp build/zenithos.bin isodir/boot/zenithos
	grub-mkrescue isodir/ -o zenithos.iso
