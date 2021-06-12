cd C:\Users\nadav\CLionProjects\learnC++\src
make
move kernel.bin ../iso/kernel/kernel.bin
make clean
cd ..
mkisofs -R -b boot/grub/stage2_eltorito -boot-info-table -no-emul-boot -boot-load-size 4 -o os.iso iso
qemu -cdrom os.iso