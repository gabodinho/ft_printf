/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:42:39 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/07 14:06:14 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <fcntl.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

// Function to compare the output of ft_printf and printf
int compare_output(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    
    // Capture output of ft_printf
    char ft_printf_output[1024];
	printf("my result:\n");
	int ft_printf_result = ft_printf(format, args);
	
	fflush(stdout);
    dup2(1, 2);
    close(1);
    int fd = open("/dev/null", O_WRONLY);
    dup2(fd, 1);

    va_end(args);

    // Capture output of printf
    va_start(args, format);
	printf("original result:\n");
    int printf_result = printf(format, args);
    va_end(args);

    // Compare the output and return the result
    if (/*strcmp(ft_printf_output, printf_output) == 0 && */ ft_printf_result == printf_result)
    {
        printf(GREEN "Test Passed\n" RESET);
        return 0;
    }
    else
    {
        printf(RED "Test Failed\n" RESET);
        return 1;
    }
}

int main()
{
    // Basic Test
    compare_output("Hello, World!\n");
    compare_output("The answer is %d\n", 42);
    compare_output("Character: %c\n", 'A');
    compare_output("String: %s\n", "Hello");

    // Format Specifiers Test
    compare_output("Integer: %d\n", 123);
    compare_output("Unsigned: %u\n", 456);
    compare_output("Hexadecimal: %x\n", 789);
    compare_output("Character: %c\n", 'A');
    compare_output("String: %s\n", "Hello");

    // Flag Test
    compare_output("Padded Integer: %10d\n", 123);
    compare_output("Left-aligned String: %-20s World!\n", "Hello");

    // Field Width Test
    compare_output("Field Width: %5d\n", 123);
    compare_output("Field Width: %10s\n", "Hello");

    // Precision Test
    compare_output("Precision: %.2f\n", 3.14159);
    compare_output("Precision: %.5s\n", "Hello");

    // Combination Test
    compare_output("Combination: %0#8x\n", 42);
    compare_output("Combination: %+-10d\n", -123);

    return 0;
}

