nasm -f elf32 kernel.asm -o kasm.o

#compile kernel.c file
gcc -o kc.o -c kernel.c -std=gnu99 -ffreestanding -Wall -Wextra -nostdlib -nostartfiles -Wincompatible-pointer-types -nodefaultlibs -m32

#linking the kernel with kernel.o and kasm.o files
ld -m elf_i386 -T link.ld -o kernel.bin kasm.o kc.o

grub-file --is-x86-multiboot kernel.bin

mkdir -p bin/
cp kernel.bin bin/kernel.bin
	
mkdir -p ponto_montagem_grub
	
mount -t auto bin/SO.img ponto_montagem_grub/
	
rm -fv ponto_montagem_grub/kernel.bin
	
cp -v bin/kernel.bin ponto_montagem_grub/
	
umount ponto_montagem_grub/

qemu-system-i386 -fda bin/SO.img
