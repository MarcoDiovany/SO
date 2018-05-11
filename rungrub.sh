	cp boot/grub.img bin/erdos.img
	
	mkdir -p ponto_montagem_grub_erdos
	
	mount -t auto bin/erdos.img ponto_montagem_grub_erdos/
	
	rm -fv ponto_montagem_grub_erdos/kernel.bin
	
	cp -v bin/kernel.bin ponto_montagem_grub_erdos/
	
	umount ponto_montagem_grub_erdos/

