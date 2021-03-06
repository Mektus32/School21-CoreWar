cmake_minimum_required(VERSION 3.16)
project(School21_CoreWar C)

set(CMAKE_C_STANDARD 11)

include_directories(corewar_asm/include)
include_directories(corewar_asm/libft)
include_directories(ft_printf/head)
include_directories(includes)
include_directories(libft/includes)
include_directories(new_checker/Corewar/includes)
include_directories(new_checker/Corewar/libft/includes)

add_executable(School21_CoreWar
        corewar_asm/include/asm.h
        corewar_asm/include/op.h
        corewar_asm/libft/ft_atoi.c
        corewar_asm/libft/ft_bzero.c
        corewar_asm/libft/ft_check_dimension.c
        corewar_asm/libft/ft_check_flag_spetia_type.c
        corewar_asm/libft/ft_check_un_dimension.c
        corewar_asm/libft/ft_concat_str.c
        corewar_asm/libft/ft_cop_str_left_or_right.c
        corewar_asm/libft/ft_copy_string_left.c
        corewar_asm/libft/ft_copy_string_left_wchar.c
        corewar_asm/libft/ft_copy_string_right.c
        corewar_asm/libft/ft_copy_string_right_wchar.c
        corewar_asm/libft/ft_create_new_lst_strchar.c
        corewar_asm/libft/ft_float_inf.c
        corewar_asm/libft/ft_is_flag_type_size.c
        corewar_asm/libft/ft_isalnum.c
        corewar_asm/libft/ft_isalpha.c
        corewar_asm/libft/ft_isascii.c
        corewar_asm/libft/ft_isdigit.c
        corewar_asm/libft/ft_isprint.c
        corewar_asm/libft/ft_itoa.c
        corewar_asm/libft/ft_itoa_llint.c
        corewar_asm/libft/ft_itoo.c
        corewar_asm/libft/ft_itox.c
        corewar_asm/libft/ft_lstadd.c
        corewar_asm/libft/ft_lstdel.c
        corewar_asm/libft/ft_lstdelone.c
        corewar_asm/libft/ft_lstiter.c
        corewar_asm/libft/ft_lstmap.c
        corewar_asm/libft/ft_lstnew.c
        corewar_asm/libft/ft_memalloc.c
        corewar_asm/libft/ft_memccpy.c
        corewar_asm/libft/ft_memchr.c
        corewar_asm/libft/ft_memcmp.c
        corewar_asm/libft/ft_memcpy.c
        corewar_asm/libft/ft_memdel.c
        corewar_asm/libft/ft_memmove.c
        corewar_asm/libft/ft_memset.c
        corewar_asm/libft/ft_memset_wchar.c
        corewar_asm/libft/ft_multi_strdup.c
        corewar_asm/libft/ft_numwr.c
        corewar_asm/libft/ft_octotorp_hex.c
        corewar_asm/libft/ft_printf.c
        corewar_asm/libft/ft_printf.h
        corewar_asm/libft/ft_put_decimal.c
        corewar_asm/libft/ft_put_hexadecimal.c
        corewar_asm/libft/ft_put_octal.c
        corewar_asm/libft/ft_put_percent.c
        corewar_asm/libft/ft_put_pointer.c
        corewar_asm/libft/ft_put_unsigned.c
        corewar_asm/libft/ft_putchar.c
        corewar_asm/libft/ft_putchar_fd.c
        corewar_asm/libft/ft_putchar_wchar.c
        corewar_asm/libft/ft_putendl.c
        corewar_asm/libft/ft_putendl_fd.c
        corewar_asm/libft/ft_putnbr.c
        corewar_asm/libft/ft_putnbr_fd.c
        corewar_asm/libft/ft_putstr.c
        corewar_asm/libft/ft_putstr_fd.c
        corewar_asm/libft/ft_putstr_wchar.c
        corewar_asm/libft/ft_read_format.c
        corewar_asm/libft/ft_strcat.c
        corewar_asm/libft/ft_strchr.c
        corewar_asm/libft/ft_strcl.c
        corewar_asm/libft/ft_strclr.c
        corewar_asm/libft/ft_strcmp.c
        corewar_asm/libft/ft_strcpy.c
        corewar_asm/libft/ft_strdel.c
        corewar_asm/libft/ft_strdel_wchar.c
        corewar_asm/libft/ft_strdup.c
        corewar_asm/libft/ft_strdup_wchar.c
        corewar_asm/libft/ft_strequ.c
        corewar_asm/libft/ft_strfr.c
        corewar_asm/libft/ft_striter.c
        corewar_asm/libft/ft_striteri.c
        corewar_asm/libft/ft_strjoin.c
        corewar_asm/libft/ft_strlcat.c
        corewar_asm/libft/ft_strlen.c
        corewar_asm/libft/ft_strlen_wchar.c
        corewar_asm/libft/ft_strmap.c
        corewar_asm/libft/ft_strmapi.c
        corewar_asm/libft/ft_strncat.c
        corewar_asm/libft/ft_strncmp.c
        corewar_asm/libft/ft_strncpy.c
        corewar_asm/libft/ft_strncpy_wchar.c
        corewar_asm/libft/ft_strnequ.c
        corewar_asm/libft/ft_strnew.c
        corewar_asm/libft/ft_strnew_char_wchar.c
        corewar_asm/libft/ft_strnew_wchar.c
        corewar_asm/libft/ft_strnjoin.c
        corewar_asm/libft/ft_strnjoinfree.c
        corewar_asm/libft/ft_strnstr.c
        corewar_asm/libft/ft_strrchr.c
        corewar_asm/libft/ft_strsplit.c
        corewar_asm/libft/ft_strstr.c
        corewar_asm/libft/ft_strsub.c
        corewar_asm/libft/ft_strtrim.c
        corewar_asm/libft/ft_tolower.c
        corewar_asm/libft/ft_toupper.c
        corewar_asm/libft/ft_un_itoa.c
        corewar_asm/libft/get_next_line.c
        corewar_asm/libft/get_next_line.h
        corewar_asm/libft/libft.h
        corewar_asm/libft/sys_err.c
        corewar_asm/libft/type_char.c
        corewar_asm/libft/type_float.c
        corewar_asm/libft/type_float2.c
        corewar_asm/libft/type_string.c
        corewar_asm/source/lable_add_list.c
        corewar_asm/source/arguments_check_two.c
        corewar_asm/source/arguments_check_one.c
        corewar_asm/source/error_and_clean_memory.c
        corewar_asm/source/arguments.c
        corewar_asm/source/init_agr.c
        corewar_asm/source/operations.c
        corewar_asm/source/main.c
        corewar_asm/source/read_comment_champ.c
        corewar_asm/source/arguments_get.c
        corewar_asm/source/read_name_comment.c
        corewar_asm/source/label.c
        corewar_asm/source/write.c
        ft_printf/head/libft.h
        ft_printf/head/libftprintf.h
        ft_printf/source/flag_check.c
        ft_printf/source/format_check.c
        ft_printf/source/ft_int_base.c
        ft_printf/source/ft_itoa_ll.c
        ft_printf/source/one.c
        ft_printf/source/print_c_u.c
        ft_printf/source/print_d.c
        ft_printf/source/print_f.c
        ft_printf/source/print_num.c
        ft_printf/source/print_o_x.c
        ft_printf/source/print_str.c
        ft_printf/source/str_format.c
        includes/corewar.h
        includes/ft_printf.h
        includes/libft.h
        includes/libftprintf.h
        includes/op.h
        libft/includes/get_next_line.h
        libft/includes/libft.h
        libft/ft_abs.c
        libft/ft_absf.c
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_count_words.c
        libft/ft_free_join.c
        libft/ft_free_strjoin_duo.c
        libft/ft_free_strjoin_rev.c
        libft/ft_frtwarr.c
        libft/ft_ftoa.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_isspace.c
        libft/ft_itoa.c
        libft/ft_list_add.c
        libft/ft_list_foreach_if.c
        libft/ft_list_push_back.c
        libft/ft_list_remove_free_if.c
        libft/ft_lstadd.c
        libft/ft_lstaddback.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_ltoa.c
        libft/ft_ltoa_base.c
        libft/ft_max.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_min.c
        libft/ft_pow.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_setbackground_fd.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlcpy.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strrev.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtolower.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/ft_truncf.c
        libft/ft_ultoa.c
        libft/ft_ultoa_base.c
        libft/get_next_line.c
        new_checker/Corewar/includes/asm.h
        new_checker/Corewar/includes/corewar.h
        new_checker/Corewar/includes/deasm.h
        new_checker/Corewar/includes/fixed_io.h
        new_checker/Corewar/includes/ft_fct_tab.h
        new_checker/Corewar/includes/ft_printf.h
        new_checker/Corewar/includes/label.h
        new_checker/Corewar/includes/lexer.h
        new_checker/Corewar/includes/libft.h
        new_checker/Corewar/includes/op.h
        new_checker/Corewar/includes/parser.h
        new_checker/Corewar/includes/ressources.h
        new_checker/Corewar/includes/scanner.h
        new_checker/Corewar/includes/viewer.h
        new_checker/Corewar/libft/includes/ft_fct_tab.h
        new_checker/Corewar/libft/includes/ft_printf.h
        new_checker/Corewar/libft/includes/libft.h
        new_checker/Corewar/libft/srcs/ft_printf/buffer.c
        new_checker/Corewar/libft/srcs/ft_printf/cast_mod.c
        new_checker/Corewar/libft/srcs/ft_printf/format.c
        new_checker/Corewar/libft/srcs/ft_printf/ft_nblen.c
        new_checker/Corewar/libft/srcs/ft_printf/ft_nblen_b.c
        new_checker/Corewar/libft/srcs/ft_printf/ft_power.c
        new_checker/Corewar/libft/srcs/ft_printf/ft_printf.c
        new_checker/Corewar/libft/srcs/ft_printf/ft_u_nblen.c
        new_checker/Corewar/libft/srcs/ft_printf/ft_u_power.c
        new_checker/Corewar/libft/srcs/ft_printf/fwp_bin.c
        new_checker/Corewar/libft/srcs/ft_printf/fwp_char.c
        new_checker/Corewar/libft/srcs/ft_printf/fwp_hex.c
        new_checker/Corewar/libft/srcs/ft_printf/fwp_int.c
        new_checker/Corewar/libft/srcs/ft_printf/fwp_oct.c
        new_checker/Corewar/libft/srcs/ft_printf/fwp_ptr.c
        new_checker/Corewar/libft/srcs/ft_printf/fwp_u_int.c
        new_checker/Corewar/libft/srcs/ft_printf/fwp_wchar.c
        new_checker/Corewar/libft/srcs/ft_printf/fwp_wstr.c
        new_checker/Corewar/libft/srcs/ft_printf/lst_arg.c
        new_checker/Corewar/libft/srcs/ft_printf/num_field.c
        new_checker/Corewar/libft/srcs/ft_printf/parser.c
        new_checker/Corewar/libft/srcs/ft_printf/str_field.c
        new_checker/Corewar/libft/srcs/get_next_line/ft_getline.c
        new_checker/Corewar/libft/srcs/get_next_line/get_next_line.c
        new_checker/Corewar/libft/srcs/memory/ft_bzero.c
        new_checker/Corewar/libft/srcs/memory/ft_memalloc.c
        new_checker/Corewar/libft/srcs/memory/ft_memccpy.c
        new_checker/Corewar/libft/srcs/memory/ft_memchr.c
        new_checker/Corewar/libft/srcs/memory/ft_memcmp.c
        new_checker/Corewar/libft/srcs/memory/ft_memcpy.c
        new_checker/Corewar/libft/srcs/memory/ft_memdel.c
        new_checker/Corewar/libft/srcs/memory/ft_memmove.c
        new_checker/Corewar/libft/srcs/memory/ft_memset.c
        new_checker/Corewar/libft/srcs/print/ft_putchar.c
        new_checker/Corewar/libft/srcs/print/ft_putchar_fd.c
        new_checker/Corewar/libft/srcs/print/ft_putendl.c
        new_checker/Corewar/libft/srcs/print/ft_putendl_fd.c
        new_checker/Corewar/libft/srcs/print/ft_putnbr.c
        new_checker/Corewar/libft/srcs/print/ft_putnbr_fd.c
        new_checker/Corewar/libft/srcs/print/ft_putstr.c
        new_checker/Corewar/libft/srcs/print/ft_putstr_fd.c
        new_checker/Corewar/libft/srcs/single_linked_list/ft_lstadd.c
        new_checker/Corewar/libft/srcs/single_linked_list/ft_lstaddback.c
        new_checker/Corewar/libft/srcs/single_linked_list/ft_lstappend.c
        new_checker/Corewar/libft/srcs/single_linked_list/ft_lstdel.c
        new_checker/Corewar/libft/srcs/single_linked_list/ft_lstdelone.c
        new_checker/Corewar/libft/srcs/single_linked_list/ft_lstinttab.c
        new_checker/Corewar/libft/srcs/single_linked_list/ft_lstiter.c
        new_checker/Corewar/libft/srcs/single_linked_list/ft_lstlen.c
        new_checker/Corewar/libft/srcs/single_linked_list/ft_lstmap.c
        new_checker/Corewar/libft/srcs/single_linked_list/ft_lstnew.c
        new_checker/Corewar/libft/srcs/single_linked_list/ft_lstpop.c
        new_checker/Corewar/libft/srcs/single_linked_list/ft_lstpush.c
        new_checker/Corewar/libft/srcs/strings/ft_strcat.c
        new_checker/Corewar/libft/srcs/strings/ft_strchr.c
        new_checker/Corewar/libft/srcs/strings/ft_strclr.c
        new_checker/Corewar/libft/srcs/strings/ft_strcmp.c
        new_checker/Corewar/libft/srcs/strings/ft_strcpy.c
        new_checker/Corewar/libft/srcs/strings/ft_strdel.c
        new_checker/Corewar/libft/srcs/strings/ft_strdup.c
        new_checker/Corewar/libft/srcs/strings/ft_strequ.c
        new_checker/Corewar/libft/srcs/strings/ft_striter.c
        new_checker/Corewar/libft/srcs/strings/ft_striteri.c
        new_checker/Corewar/libft/srcs/strings/ft_strjoin.c
        new_checker/Corewar/libft/srcs/strings/ft_strlcat.c
        new_checker/Corewar/libft/srcs/strings/ft_strlen.c
        new_checker/Corewar/libft/srcs/strings/ft_strmap.c
        new_checker/Corewar/libft/srcs/strings/ft_strmapi.c
        new_checker/Corewar/libft/srcs/strings/ft_strncat.c
        new_checker/Corewar/libft/srcs/strings/ft_strncmp.c
        new_checker/Corewar/libft/srcs/strings/ft_strncpy.c
        new_checker/Corewar/libft/srcs/strings/ft_strnequ.c
        new_checker/Corewar/libft/srcs/strings/ft_strnew.c
        new_checker/Corewar/libft/srcs/strings/ft_strnstr.c
        new_checker/Corewar/libft/srcs/strings/ft_strrchr.c
        new_checker/Corewar/libft/srcs/strings/ft_strrev.c
        new_checker/Corewar/libft/srcs/strings/ft_strsplit.c
        new_checker/Corewar/libft/srcs/strings/ft_strsplitdel.c
        new_checker/Corewar/libft/srcs/strings/ft_strstr.c
        new_checker/Corewar/libft/srcs/strings/ft_strsub.c
        new_checker/Corewar/libft/srcs/strings/ft_strtrim.c
        new_checker/Corewar/libft/srcs/utils/ft_atoi.c
        new_checker/Corewar/libft/srcs/utils/ft_isalnum.c
        new_checker/Corewar/libft/srcs/utils/ft_isalpha.c
        new_checker/Corewar/libft/srcs/utils/ft_isascii.c
        new_checker/Corewar/libft/srcs/utils/ft_isdigit.c
        new_checker/Corewar/libft/srcs/utils/ft_isdigitstr.c
        new_checker/Corewar/libft/srcs/utils/ft_islower.c
        new_checker/Corewar/libft/srcs/utils/ft_isprint.c
        new_checker/Corewar/libft/srcs/utils/ft_isspace.c
        new_checker/Corewar/libft/srcs/utils/ft_isupper.c
        new_checker/Corewar/libft/srcs/utils/ft_itoa.c
        new_checker/Corewar/libft/srcs/utils/ft_squeeze.c
        new_checker/Corewar/libft/srcs/utils/ft_tolower.c
        new_checker/Corewar/libft/srcs/utils/ft_toupper.c
        new_checker/Corewar/srcs/asm/asm.c
        new_checker/Corewar/srcs/asm/asm_utils.c
        new_checker/Corewar/srcs/asm/deasm.c
        new_checker/Corewar/srcs/asm/deasm_manage.c
        new_checker/Corewar/srcs/asm/fixed_io.c
        new_checker/Corewar/srcs/asm/label.c
        new_checker/Corewar/srcs/asm/label_init.c
        new_checker/Corewar/srcs/asm/label_utils.c
        new_checker/Corewar/srcs/asm/lexer.c
        new_checker/Corewar/srcs/asm/op.c
        new_checker/Corewar/srcs/asm/parser.c
        new_checker/Corewar/srcs/asm/parser_header.c
        new_checker/Corewar/srcs/asm/parser_init.c
        new_checker/Corewar/srcs/asm/scanner.c
        new_checker/Corewar/srcs/corewar/corewar.c
        new_checker/Corewar/srcs/corewar/get_players.c
        new_checker/Corewar/srcs/corewar/get_players_errors.c
        new_checker/Corewar/srcs/corewar/load_arena.c
        new_checker/Corewar/srcs/corewar/op.c
        new_checker/Corewar/srcs/corewar/op_shift.c
        new_checker/Corewar/srcs/corewar/operate.c
        new_checker/Corewar/srcs/corewar/operation_1.c
        new_checker/Corewar/srcs/corewar/operation_2.c
        new_checker/Corewar/srcs/corewar/operation_2b.c
        new_checker/Corewar/srcs/corewar/operation_3.c
        new_checker/Corewar/srcs/corewar/operation_4.c
        new_checker/Corewar/srcs/corewar/operation_4b.c
        new_checker/Corewar/srcs/corewar/vm_debbug.c
        new_checker/Corewar/srcs/corewar/vm_game.c
        new_checker/Corewar/srcs/corewar/vm_init_free.c
        new_checker/Corewar/srcs/corewar/vm_parsing.c
        new_checker/Corewar/srcs/corewar/vw_draw_img.c
        new_checker/Corewar/srcs/corewar/vw_draw_life.c
        new_checker/Corewar/srcs/corewar/vw_draw_tools.c
        new_checker/Corewar/srcs/corewar/vw_init.c
        new_checker/Corewar/srcs/corewar/vw_init_win.c
        new_checker/Corewar/srcs/corewar/vw_maj_process.c
        new_checker/Corewar/srcs/corewar/vw_maj_win.c
        new_checker/Corewar/srcs/corewar/vw_th_anim.c
        new_checker/Corewar/srcs/corewar/vw_th_core.c
        new_checker/Corewar/srcs/corewar/vw_th_input.c
        new_checker/Corewar/srcs/corewar/vw_th_render.c
        new_checker/Corewar/srcs/corewar/vw_th_timer.c
        src_cor/arena.c
        src_cor/arg.c
        src_cor/carr_list.c
        src_cor/champ.c
        src_cor/do_op.c
        src_cor/ft_add.c
        src_cor/ft_aff.c
        src_cor/ft_and.c
        src_cor/ft_fork_lfork.c
        src_cor/ft_ld.c
        src_cor/ft_ldi.c
        src_cor/ft_liba.c
        src_cor/ft_live.c
        src_cor/ft_or_xor.c
        src_cor/ft_st.c
        src_cor/ft_sti.c
        src_cor/ft_sub.c
        src_cor/ft_zjmp.c
        src_cor/go_cor.c
        src_cor/main.c
        src_cor/parse_av.c
        src_cor/print_code.c
        src_cor/read_byte.c
        src_cor/visu_cicle.c
        src_cor/visu_init.c
        src_cor/write_map.c corewar_asm/source/write_labels.c corewar_asm/source/file.c)
