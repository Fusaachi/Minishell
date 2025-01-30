/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:47:38 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/30 15:17:59 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}t_list;

/**
 * @brief Check if the character is alphanumeric (A-Z, a-z, 0-9)
 * 
 * @param c The character to check
 * 
 * @return 1 if the character is alphanumeric, 0 otherwise
 */
int		ft_isalnum(int c);
/**
 * @brief Check if the character is alphabetic (A-Z, a-z)
 * 
 * @param c The character to check
 * 
 * @return 1 if the character is alphabetic, 0 otherwise
 */
int		ft_isalpha(int c);
/**
 * @brief Check if the character is an ASCII character
 * 
 * @param c The character to check
 * 
 * @return 1 if the character is an ASCII character, 0 otherwise
 */
int		ft_isascii(int c);
/**
 * @brief Check if the character is a digit (0-9)
 * 
 * @param i The character to check
 * 
 * @return 1 if the character is a digit, 0 otherwise
 */
int		ft_isdigit(int i);
/**
 * @brief Check if the character is printable
 * 
 * @param c The character to check
 * 
 * @return 1 if the character is printable, 0 otherwise
 */
int		ft_isprint(int c);

/**
 * @brief Add element to the end of the list
 * 
 * @param lst The address of a pointer to the first element of the list
 * 
 * @param new The element to add to the list
 */
void	ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief Add element to the beginning of the list
 * 
 * @param lst The address of a pointer to the first element of the list
 * 
 * @param new The element to add to the list
 */
void	ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief Clear the list
 * 
 * @param lst The address of a pointer to the first element of the list
 * 
 * @param del The function to delete the content of the element
 */
void	ft_lstclear(t_list **lst, void (*del)(int));
/**
 * @brief Delete the element of the list
 * 
 * @param lst The element to delete
 * 
 * @param del The function to delete the content of the element
 * 
 * @return The next element of the list
 */
void	ft_lstdelone(t_list *lst, void (*del)(int));
/**
 * @brief Apply the function to each element of the list
 * 
 * @param lst The first element of the list
 * 
 * @param f The function to apply to each element
 */
void	ft_lstiter(t_list *lst, void (*f)(int));
/**
 * @brief Return the last element of the list
 * 
 * @param lst The first element of the list
 * 
 * @return The last element of the list, NULL if the list is empty
 */
t_list	*ft_lstlast(t_list *lst);
/**
 * @brief Applies a function to each element of a list and creates a new list
 * 
 * @param lst The first element of the list
 * 
 * @param f The function to apply to each element
 * 
 * @param del The function to delete the content of the element
 * 
 * @return The new list
 */
t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int));
/**
 * @brief Create a new element of the list
 * 
 * @param content The content of the element
 * 
 * @return The new element of the list
 */
t_list	*ft_lstnew(int content);
/**
 * @brief Return the number of elements in the list
 * 
 * @param lst The first element of the list
 * 
 * @return The number of elements in the list
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s
 *        for the first instance of c. Both c and the bytes of the memory
 *        area pointed to by s are interpreted as unsigned char.
 *
 * @param s Pointer to the memory area to be scanned.
 * @param c The value to be located. The value is passed as an int, but it is
 *          internally converted to an unsigned char.
 * @param n The number of bytes to be analyzed.
 *
 * @return A pointer to the matching byte or NULL if the character does not
 *         occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n);
/**
 * @brief Compares the first n bytes of the memory areas s1 and s2.
 *
 * @param ptrstr1 Pointer to the first memory area.
 * @param ptrstr2 Pointer to the second memory area.
 * @param n The number of bytes to be compared.
 *
 * @return An integer less than, equal to, or greater than zero if the first n
 *         bytes of s1 is found, respectively, to be less than, to match, or be
 *         greater than the first n bytes of s2.
 */
int		ft_memcmp(const void *ptrstr1, const void *ptrstr2, size_t n);
/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *        The memory areas must not overlap.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n The number of bytes to be copied.
 *
 * @return A pointer to the destination memory area dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);
/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *        The memory areas may overlap.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n The number of bytes to be copied.
 *
 * @return A pointer to the destination memory area dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);
/**
 * @brief Copies the character c (an unsigned char) to the first n characters
 *        of the string pointed to, by the argument dest.
 *
 * @param dest Pointer to the memory area.
 * @param c The character to be copied.
 * @param count The number of characters to be copied.
 *
 * @return A pointer to the memory area dest.
 */
void	*ft_memset(void *dest, int c, size_t count);

/**
 * @brief Convert a string to a long integer
 * 
 * @param str The string to convert
 * 
 * @return The long integer
 */
long	ft_atol(const char *str);
/**
 * @brief Convert a string to an integer
 * 
 * @param str The string to convert
 * 
 * @return The integer
 */
void	ft_bzero(void *s, size_t n);
/**
 * @brief Allocate memory and set it to zero
 * 
 * @param nmemb The number of elements
 * 
 * @param size The size of each element
 * 
 * @return The pointer to the allocated memory
 */
void	*ft_calloc(size_t nmemb, size_t size);
/**
 * @brief Free a double array
 * 
 * @param strs The double array to free
 */
void	ft_free(char **strs);
/**
 * @brief Convert an integer to a string
 * 
 * @param n The integer to convert
 * 
 * @return The string
 */
char	*ft_itoa(int n);
/**
 * @brief Split a string into an array of strings
 * using the character c as a delimiter
 * 
 * @param s The string to split
 * 
 * @param c The delimiter
 * 
 * @return The array of strings
 */
char	**ft_split(char const *s, char c);
/**
 * @brief Extracts a substring from a given string.
 *
 * This function allocates (with malloc) and returns a substring from the
 * string 's'.
 * The substring begins at index 'start' and is of maximum size 'len'.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Prints a character to the specified file descriptor
 * 
 * @param c The character to print
 * 
 * @param fd The file descriptor
 */
void	ft_putchar_fd(char c, int fd);
/**
 * @brief Prints a string to the specified file descriptor
 * but adds a newline at the end
 * 
 * @param s The string to print
 * 
 * @param fd The file descriptor
 */
void	ft_putendl_fd(char *s, int fd);
/**
 * @brief Prints an integer to the specified file descriptor
 * 
 * @param n The integer to print
 * 
 * @param fd The file descriptor
 */
void	ft_putnbr_fd(int n, int fd);
/**
 * @brief Prints a string to the specified file descriptor
 * 
 * @param s The string to print
 * 
 * @param fd The file descriptor
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Locate the first occurrence of a character in a string
 * 
 * @param s The string to be searched
 * @param c The character to be located
 * 
 * @return A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found
 */
char	*ft_strchr(const char *s, int c);
/**
 * @brief Malloc and copy a string
 * 
 * @param s The string to copy
 * 
 * @return The copy of the string
 */
char	*ft_strdup(const char *s);
/**
 * @brief Apply a function to each element of a string
 * 
 * @param s The string to apply the function to
 * 
 * @param f The function to apply to each element
 * 
 * @return The new string
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/**
 * @brief Joins two strings
 * 
 * @param s1 The first string
 * 
 * @param s2 The second string
 * 
 * @return The new string
 */
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief Appends the null-terminated string src to the end of dst.
 *        It will append at most n - strlen(dst) - 1 bytes, null-terminating
 *        the result.
 *
 * @param dst The destination string to which src will be appended.
 * @param src The source string which will be appended to dst.
 * @param n The total size of the destination buffer.
 *
 * @return The total length of the string it tried to create, that means the
 *         initial length of dst plus the length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t n);
/**
 * @brief Copies up to size - 1 characters from the null-terminated
 * string src to dest null-terminating the result.
 *
 * @param dest The destination buffer where the content is to be copied.
 * @param src The source string to be copied.
 * @param size The size of the destination buffer.
 * @return The total length of the string it tried to create,
 * which is the length of src.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
/**
 * @brief Get the length of a string
 * 
 * @param str The string
 * 
 * @return The length of the string
 */
size_t	ft_strlen(const char *str);
/**
 * @brief Applies a function to each character of a string to 
 * create a new string.
 * @param s The input string.
 * @param f The function to apply to each character. It takes an 
 * unsigned int (index) and a char (character) as arguments.
 *
 * This function allocates memory for a new string,
 * applies the function 'f' to each character of the input string 's'
 * and stores the result in the new string.
 * The new string is null-terminated.
 *
 * @return A pointer to the new string, or NULL if memory allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief Compares two strings until the limit set by the length
 * 
 * @param first The first string
 * 
 * @param second The second string
 * 
 * @param length The maximum number of characters to compare
 * 
 * @return 0 if the strings are identical, a negative value if the first string
 * is less than the second string, or a positive value if the first string is
 * greater than the second string
 */
int		ft_strncmp(const char *first, const char *second, size_t length);
/**
 * @brief Locates the first occurrence of the null-terminated string s2 in the 
 *        string s1, where not more than n characters are searched.
 *
 * @param s1 The main C string to be scanned.
 * @param s2 The small string to be searched within s1.
 * @param n The maximum number of characters to be searched.
 *
 * This function locates the first occurrence of the null-terminated string s2 
 * in the string s1, where not more than n characters are searched. Characters 
 * that appear after a `\0` character are not searched. If s2 is an empty  
 * string, s1 is returned; if s2 occurs nowhere in s1, NULL is returned.
 *
 * @return A pointer to the first occurrence of s2 in s1
 * or NULL if s2 is not found.
 */
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
/**
 * @brief Locates the last occurrence of a character in a string.
 *
 * This function searches for the last occurrence of the character `c` 
 * in the string `s`. The search includes the terminating null character.
 *
 * @param s The string to be searched.
 * @param c The character to be located.
 * @return A pointer to the last occurrence of the character `c`
 * in the string `s`, or NULL if the character is not found.
 */
char	*ft_strrchr(const char *s, int c);
/**
 * @brief Trims the characters from the beginning and end
 * of a string that are present in the given set.
 *
 * This function allocates memory for a new string, which is a copy
 * of the input string `s1` with all characters from the set `set` removed
 * from the beginning and the end. The new string is null-terminated.
 *
 * @param s1 The input string to be trimmed.
 * @param set The set of characters to be trimmed from `s1`.
 * @return A pointer to the newly allocated trimmed string,
 * or NULL if memory allocation fails or if `s1` or `set` is NULL.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Convert a character to lowercase
 * 
 * @param c The character to convert
 * 
 * @return The lowercase character
 */
int		ft_tolower(int c);
/**
 * @brief Convert a character to uppercase
 * 
 * @param c The character to convert
 * 
 * @return The uppercase character
 */
int		ft_toupper(int c);

/**
 * @brief Checks for the presence of a newline character in the given buffer.
 *
 * This function iterates through the provided buffer and checks each character.
 * If a newline character ('\n') is found, the function returns the index of the
 * newline character. If no newline character is found, the function returns -1.
 *
 * @param buffer The buffer to be checked for a newline character.
 * @return The index of the newline character if found, otherwise -1.
 */
int		ft_check(char *buffer);
/**
 * @brief Clears the buffer from a specified index
 * and shifts the remaining content to the start.
 *
 * This function takes a buffer and an index, and clears the buffer
 * from the specified index onwards. It shifts the remaining content to the
 * start of the buffer and returns the modified buffer.
 *
 * @param buffer The buffer to be cleared and modified.
 * @param i The index from which to start clearing the buffer.
 * @return The modified buffer with the content shifted to the start.
 */
char	*ft_clearbuffer(char *buffer, int i);
/**
 * @brief Joins two strings, `str` and `buffer`, into a new string.
 * 
 * This function concatenates the contents of `str` and `buffer` into a new
 * dynamically allocated string. The function stops copying from `buffer` if
 * it encounters a newline character (`\n`), which is also included in the
 * resulting string. The original `str` is freed before returning the new string.
 * 
 * @param str The first string to be joined. This string will be freed.
 * @param buffer The second string to be joined.
 * @return A new string that is the result of concatenating `str` and `buffer`.
 *         If either `str` or `buffer` is NULL, or if memory allocation fails,
 *         the function returns NULL.
 */
char	*ft_strjoin_gnl(char *str, char *buffer);
/**
 * @brief Reads a line from a file descriptor.
 * 
 * This function reads a line from the file descriptor `fd` and returns it as a
 * string. The function stops reading when a newline character is encountered,
 * and the newline character is included in the returned string. The function
 * returns NULL if an error occurs or if the end of the file is reached.
 * 
 * @param fd The file descriptor from which to read.
 * 
 * @return The line read from the file descriptor, or NULL on error or EOF.
 */
char	*get_next_line(int fd);

/**
 * Counts the number of digits in a given long integer.
 *
 * This function takes a long integer as input and returns the number of digits
 * in the integer. If the integer is negative, the sign is taken into account
 * and the count includes the negative sign.
 *
 * @param n The long integer whose digits are to be counted.
 * @return The number of digits in the given long integer,
 * including the sign if negative.
 */
size_t	ft_countnb_long(long long n);
/**
 * @brief Prints something to the standard output.
 * 
 * This function is a variadic function that takes
 * a format string and a variable number of arguments.
 * It formats and prints the arguments according to the format string.
 * The function returns the number of characters printed,
 * or -1 if an error occurs.
 * 
 * The format string can contain the following specifiers:
 *  * - 'i' or 'd': Prints an integer.
 * - 'c': Prints a character.
 * - 's': Prints a string.
 * - 'u': Prints an unsigned integer.
 * - 'x': Prints an integer in lowercase hexadecimal format.
 * - 'X': Prints an integer in uppercase hexadecimal format.
 * - 'p': Prints a pointer address.
 * - '%': Prints a percent sign.
 * 
 * @param format The format string that specifies how subsequent
 * arguments are formatted.
 * 
 * @return The number of characters printed, or -1 if an error occurs.
 */
int		ft_printf(const char *format, ...);
/**
 * @brief Prints a pointer to the standard output.
 * 
 * @param adresse The pointer to print.
 * 
 * @return The number of characters printed.
 */
int		ft_printpointer(void *adresse);
/**
 * @brief Prints an unsigned integer to the standard output.
 * 
 * @param integer The unsigned integer to print.
 * 
 * @return The number of characters printed.
 */
int		ft_printunsigned(unsigned int integer);
/**
 * @brief Prints a character to the standard output.
 * 
 * @param c The character to print.
 * 
 * @return The number of characters printed.
 */
int		ft_putchar(char c);
/**
 * @brief Prints an integer to the standard output.
 * 
 * @param integer The integer to print.
 * 
 * @return The number of characters printed.
 */
int		ft_putnbr(int integer);
/**
 * @brief Prints a integer with a base to the standard output.
 * 
 * @param integer The integer to print.
 * 
 * @param base The base to use for the conversion.
 * 
 * @return The number of characters printed.
 */
int		ft_putnbrbase(unsigned int integer, char *base);
/**
 * @brief Prints a string to the standard output.
 * 
 * @param str The string to print.
 * 
 * @return The number of characters printed.
 */
int		ft_putstr(char *str);
/**
 * ft_putparams - Processes format specifiers and prints corresponding arguments.
 * @format: The format string containing the specifiers.
 * @i: Pointer to the current index in the format string.
 * @count: The current count of characters printed.
 * @ap: The list of arguments to be printed.
 *
 * Returns the updated count of characters printed.
 */
int		ft_putparams(const char *format, int *i, int count, va_list ap);

#endif
