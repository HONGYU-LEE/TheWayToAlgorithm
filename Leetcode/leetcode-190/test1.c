uint32_t reverseBits(uint32_t n) {
    unsigned int ret = 0, i;
	for (i = 0; i < 32; i++)
	{
		ret <<= 1;
		ret ^= ((n >> i) & 1);
	}
	return ret;
}
