cmake_minimum_required(VERSION 3.9)
project(ft_printf)

set(CMAKE_CXX_STANDARD 11)

add_executable(ft_printf
        author
        ft_atoi.c
        ft_bzero.c
        ft_chr_to_str.c
        ft_chrjoin.c
        ft_get_address.c
        ft_isdigit.c
        ft_itoa.c
        ft_memcpy.c
        ft_power.c
        ft_printf.c
        ft_putchar.c
        ft_putnbr.c
        ft_putstr.c
        ft_strcpy.c
        ft_strdel.c
        ft_strjoin.c
        ft_strlen.c
        ft_strnew.c
        ft_strsub.c
        ft_unichar.c
        ft_unistr.c
        ft_unitoa_base.c
        ft_unitoa_uppbase.c
        libft.h
        main.c
        Makefile
        set_arg.c
        get_farg.c
        ft_set_str.c
        ft_set_chr.c)