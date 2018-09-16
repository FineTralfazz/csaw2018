from string import ascii_letters, digits

BITS = "01100110 00011111 00011000 01011001 11011110 11011011 11011101 11011011 01011110 01011010 00011000 01011011 10011001 00011111 01"
#                                                                   ^

alphabet = ascii_letters + digits


def to_chars(bits):
    num_bits = 8
    b = bits.replace(" ", '')
    return "".join([chr(int(b[x: x+num_bits], base=2)) for x in range(0, len(b), num_bits)])


if __name__ == '__main__':
    print(to_chars(BITS))
