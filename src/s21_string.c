// В этом файле не должно быть никаких других функций кроме функций библиотеки.
// Вспомогательные функции должны быть вынесены в utils.c

#include "s21_string.h"

#include <stdarg.h>
#include <stdlib.h>

#include "utils.h"

void *s21_memchr(const void *str, int c, size_t n) {
  unsigned char *ch_str = (unsigned char *)str;
  for (size_t i = 0; i < n; i++) {
    if (*ch_str == (unsigned char)c) {
      return (unsigned char *)ch_str;
    }
    ch_str++;
  }
  return S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  unsigned char *ch_str1 = (unsigned char *)str1;
  unsigned char *ch_str2 = (unsigned char *)str2;
  int difference = 0;
  for (size_t i = 0; i < n; i++) {
    difference = *ch_str1 - *ch_str2;
    if (difference != 0) break;
    ch_str1++;
    ch_str2++;
  }
  return difference;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
  unsigned char *ch_dest = (unsigned char *)dest;
  unsigned char *ch_src = (unsigned char *)src;

  for (size_t i = 0; i < n; i++) {
    *ch_dest = *ch_src;
    ch_dest++;
    ch_src++;
  }

  return dest;
}

void *s21_memset(void *str, int c, size_t n) {
  unsigned char *ch_str = (unsigned char *)str;
  unsigned char ch = (unsigned char)c;

  for (size_t i = 0; i < n; i++) {
    *ch_str = ch;
    ch_str++;
  }

  return str;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
  char *p = dest + s21_strlen(dest);
  while (*src != '\0' && n--) {
    *p++ = *src++;
    if (n == 0) {
      *p = '\0';
    }
  }
  return dest;
}

char *s21_strchr(const char *str, int c) {
  if ((char)c == '\0') return "";
  while (*str != '\0') {
    if (*str == (char)c) {
      return (char *)str;
    }
    str++;
  }
  return S21_NULL;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int len = 0;
  while (*str1 && (*str1 == *str2) && len < (int)n - 1) {
    str1++;
    str2++;
    len++;
  }
  return *str1 - *str2;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
  char *pointer = dest;

  while (*src != '\0' && n--) {
    *pointer++ = *src++;
  }

  *pointer = '\0';

  return dest;
}

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t len = 0;
  int is_equal = 0;
  for (size_t i = 0; i < s21_strlen(str1) && !is_equal; i++) {
    for (size_t j = 0; j < s21_strlen(str2) && !is_equal; j++) {
      if (str1[i] == str2[j]) is_equal = 1;
    }
    if (!is_equal) len++;
  }
  return len;
}

const char *s21_strerror(int errnum) {
  if (errnum < ERR_FIRST || errnum > ERR_LAST) {
    const char *unknown_error = "Unknown error ";
    static char error[100];
    s21_strncpy(error, "", 0);
    s21_strncat(error, unknown_error, s21_strlen(unknown_error));
    char *number = int_to_str(errnum);
    s21_strncat(error, number, s21_strlen(number));
    free(number);
    return error;
  } else {
    const char *s21_error[] = s21_error_array;
    return s21_error[errnum];
  }
}

size_t s21_strlen(const char *str) {
  size_t length = 0;

  for (; *(str + length); length++)
    ;

  return length;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *ptr = S21_NULL;
  int index = -1;
  for (size_t i = 0; i < s21_strlen(str1) && index == -1; i++) {
    for (size_t j = 0; j < s21_strlen(str2) && index == -1; j++) {
      if (str1[i] == str2[j]) {
        index = i;
      }
    }
  }
  if (index != -1) ptr = str1 + index;
  return (char *)ptr;
}

char *s21_strrchr(const char *str, int c) {
  const char *index = S21_NULL;
  for (size_t i = 0; i <= s21_strlen(str); i++) {
    if (str[i] == c) {
      index = str + i;
    }
  }
  return (char *)index;
}

char *s21_strstr(const char *haystack, const char *needle) {
  int is_equal;

  if (*needle == '\0') {
    return (char *)haystack;
  }

  while (*haystack != '\0') {
    if (*haystack == *needle) {
      is_equal = 1;

      for (int i = 0; needle[i] != '\0'; i++) {
        if (haystack[i] != needle[i]) {
          is_equal = 0;
        }
      }

      if (is_equal) {
        return (char *)haystack;
      }
    }

    haystack++;
  }

  return S21_NULL;
}

char *s21_strtok(char *str, const char *delim) {
  static char *nextToken = S21_NULL;

  if (str == S21_NULL) {
    return S21_NULL;
  }

  if (str != S21_NULL) {
    nextToken = str;
  }

  // Пропустить делиметры в начале
  while (*nextToken != '\0' && s21_strchr(delim, *nextToken) != S21_NULL) {
    nextToken++;
  }

  if (*nextToken == '\0') {
    return S21_NULL;
  }

  // Сохранить указатель на начало токена
  char *token = nextToken;

  // Найти конец токена
  while (*nextToken != '\0' && s21_strchr(delim, *nextToken) == S21_NULL) {
    nextToken++;
  }

  // Если не конец строки, добавить конец строки и передвинуть указатель токена
  // на следующий char
  if (*nextToken != '\0') {
    *nextToken = '\0';
    nextToken++;
  }

  return token;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list v1;
  va_start(v1, format);
  short int hd;
  int d;
  long long int ld;
  char *start = str;
  char ch;
  double db;
  unsigned int ud;
  while (*format) {
    if (*format == '%') {
      format++;
      OPTIONS opt = {0};
      DATATYPES types = {0};
      get_flags(&format, &opt);
      get_width(&format, &opt);
      get_accuracy(&format, &opt);
      get_length(&format, &opt);
      get_specificator(&format, &types);
      if (types.c || types.percent) {
        ch = va_arg(v1, int);
        typer_ch(&str, opt, ch);
      }
      if (types.d) {
        if (opt.length == 0) {
          d = va_arg(v1, int);
          ld = (long long int)d;
          typer_int(&str, opt, ld);
        }
        if (opt.length == 1) {
          d = va_arg(v1, int);
          hd = (short int)d;
          ld = (long long int)hd;
          typer_int(&str, opt, ld);
        }
        if (opt.length == 2) {
          ld = va_arg(v1, long long int);
          typer_int(&str, opt, ld);
        }
      }
      if (types.f) {
        db = va_arg(v1, double);
        typer_db(&str, opt, db);
      }
      if (types.s) {
        char *s = va_arg(v1, char *);
        typer_s(&str, opt, s);
      }
      if (types.u) {
        ud = va_arg(v1, unsigned int);
        typer_unsigned_int(&str, opt, ud);
      }
    } else {
      *str = *format;
      str++;
      format++;
    }
  }

  va_end(v1);
  *str = '\0';
  int length = str - start;
  return length;
}

void *s21_to_upper(const char *str) {
  if (str) {
    static char our_str1[S21_BUFFER_LEN];
    s21_strncpy(our_str1, str, s21_strlen(str) + 1);
    for (char *i = our_str1; *i; i++) {
      if (*i >= 'a' && *i <= 'z') {
        *i -= 32;
      }
    }
    return (void *)our_str1;
  }
  return S21_NULL;
}

void *s21_to_lower(const char *str) {
  if (str) {
    static char our_str2[S21_BUFFER_LEN];
    s21_strncpy(our_str2, str, s21_strlen(str) + 1);
    for (char *i = our_str2; *i; i++) {
      if (*i >= 'A' && *i <= 'Z') {
        *i += 32;
      }
    }
    return (void *)our_str2;
  }
  return S21_NULL;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  size_t src_len = 0;
  size_t str_len = 0;
  if (src != S21_NULL) {
    src_len = s21_strlen(src);
  }
  if (str != S21_NULL) {
    str_len = s21_strlen(str);
  }
  if (start_index <= src_len) {
    static char result[S21_BUFFER_LEN];
    for (size_t i = 0; i < start_index; i++) {
      result[i] = src[i];
    }
    for (size_t i = start_index; i < start_index + str_len; i++) {
      result[i] = str[i - start_index];
    }
    for (size_t i = start_index + str_len; i < src_len + str_len; i++) {
      result[i] = src[i - str_len];
    }
    return (void *)result;
  }
  return S21_NULL;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src != S21_NULL && trim_chars != S21_NULL) {
    int size = s21_strlen(src) + 1;
    static char src_new[S21_BUFFER_LEN];
    int i = 0, k = size - 2, flag = 1, l;
    while (src[i] && flag) {
      flag = 0;
      for (int j = 0; trim_chars[j]; j++) {
        if (src[i] == trim_chars[j]) {
          flag = 1;
          i++;
          break;
        }
      }
    }
    flag = 1;
    while (k >= 0 && flag) {
      flag = 0;
      for (int j = 0; trim_chars[j]; j++) {
        if (src[k] == trim_chars[j]) {
          flag = 1;
          k--;
          break;
        }
      }
    }
    k = k - i;
    for (l = 0; l <= k; i++, l++) src_new[l] = src[i];
    src_new[l] = '\0';
    return (void *)src_new;
  }
  return S21_NULL;
}
