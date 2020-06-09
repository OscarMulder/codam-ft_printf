# codam-ft_printf
This project is an implementation of the C printf function. It handles quite a lot of conversions and flags (including basic floats), but it is very slow (it doesn't use a buffer and each write() call only writes one char).
