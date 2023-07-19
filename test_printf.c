/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:17:01 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/12 11:59:00 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"

#define BUFFER_SIZE 1024

char* capture_stdout(const char *format, va_list ap)
{
	va_list args;
    va_copy(args, ap);
    // Save the original standard output file descriptor
    int original_stdout = dup(fileno(stdout));

    // Create a pipe to redirect the standard output
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return NULL;
    }

    // Duplicate the write end of the pipe to standard output
    if (dup2(pipefd[1], fileno(stdout)) == -1) {
        perror("dup2");
        return NULL;
    }

    // Close the write end of the pipe
    close(pipefd[1]);

    // Call the provided function to perform the output operation
	ft_printf(format, args);

    // Restore the original standard output
    fflush(stdout);
    dup2(original_stdout, fileno(stdout));
    close(original_stdout);

    // Read the contents of the pipe into a string buffer
    char* buffer = malloc(BUFFER_SIZE);
    ssize_t nbytes = read(pipefd[0], buffer, BUFFER_SIZE - 1);
    if (nbytes == -1) {
        perror("read");
        free(buffer);
        return NULL;
    }
    buffer[nbytes] = '\0';

    return buffer;
}

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

// Function to compare the output of ft_printf and printf
int compare_output(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    
    // Capture output of ft_printf
	printf("my result:\n");
    char *ft_printf_output = capture_stdout(format, args);
	va_end(args);

	va_start(args, format);
	int ft_printf_result = ft_printf(format, args);
	va_end(args);

    va_start(args, format);
	char printf_output[BUFFER_SIZE];
	snprintf(printf_output, BUFFER_SIZE, format, args);
	va_end(args);
	
	printf("\nog result:\n");
	va_start(args, format);
	int printf_result = printf(format, args);
    va_end(args);

    // Compare the output and return the result
    if (strcmp(ft_printf_output, printf_output) == 0 && ft_printf_result == printf_result)
    {
        printf(GREEN "\nTest Passed\n" RESET);
        return 0;
    }
    else
    {
        printf(RED "\nTest Failed\n" RESET);
        return 1;
    }
}



// Example usage
/*
void test_function() {
    printf("This is a test message.\n");
    printf("Another line of text.\n");
}
*/

int main(void)
{
	compare_output("print this: %d", 1234);
	ft_printf("%d\n", -1324);
    return 0;
}

