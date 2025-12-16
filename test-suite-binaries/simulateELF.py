from elftools.elf.elffile import ELFFile

with open("mini_rop", "rb") as f:
    elf = ELFFile(f)
    text = elf.get_section_by_name('.text')
    print(text.data())
