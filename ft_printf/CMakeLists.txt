cmake_minimum_required(VERSION 3.9)
project(ft_printf)

set(CMAKE_CXX_STANDARD 11)

add_executable(ft_printf
        author
        ft_atoi.c
        ft_binary.c
        ft_bzero.c
        ft_chr_to_str.c
        ft_chrjoin.c
        ft_get_address.c
        ft_hex_itoa.c
        ft_isdigit.c
        ft_itoa.c
        ft_lltoa.c
        ft_memcpy.c
        ft_oct_itoa.c
        ft_power.c
        ft_printf.c
        ft_putchar.c
        ft_putnbr.c
        ft_putstr.c
        ft_strcpy.c
        ft_strdel.c
        ft_strdup.c
        ft_strjoin.c
        ft_strlen.c
        ft_strnew.c
        ft_strsub.c
        ft_unichar.c
        ft_unistr.c
        ft_unitoa.c
        libft.h
        main.c
        Makefile
        set_arg.c
        set_chr.c
        set_integer.c)
