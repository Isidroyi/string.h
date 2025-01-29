#include "utils.h"

#include <stdlib.h>

#include "s21_string.h"

int get_number_length(int number) {
  int length = 1;
  if (number < 0) {
    length++;
    number = -number;
  }
  while (number >= 10) {
    length++;
    number /= 10;
  }
  return length;
}

char* int_to_str(int number) {
  int length = get_number_length(number);
  char* result = (char*)malloc((length + 1) * sizeof(char));
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  result[length] = '\0';
  if (number < 0) {
    length--;
    number *= -1;
    for (int i = 0; i < length; ++i) {
      result[length - i] = '0' + number % 10;
      number /= 10;
    }
    result[0] = '-';
  } else {
    for (int i = 0; i < length; ++i) {
      result[length - i - 1] = '0' + number % 10;
      number /= 10;
    }
  }

  return result;
}

int count_double_symb(double x, int accur, int zero_accur, int need_symb) {
  int result = 0;
  if (x < 0) {
    result++;
    x *= -1;
  } else if (need_symb)
    result++;
  int intpart = (int)x;
  while (intpart > 0) {
    intpart /= 10;
    result++;
  }
  if (!zero_accur) {
    result++;
    if (accur == 0)
      result += 6;
    else
      result += accur;
  }
  return result;
}

int count_starting(const char* str1, const char* str2) {
  int result = 0;

  for (; *str1 != '\0'; str1++) {
    char* tmp = (char*)str2;
    int flag = 0;
    for (; *tmp != '\0'; tmp++) {
      if (*str1 == *tmp) flag = 1;
    }
    if (flag == 1)
      result++;
    else
      return result;
  }
  return result;
}

int get_flags(const char** format, OPTIONS* options) {
  int result = count_starting(*format, " +-#0");
  for (int i = 0; i < result; i++) {
    if (**format == '-') {
      options->left_corner = 1;
    }
    if (**format == '+') {
      options->show_sign = 1;
    }
    if (**format == ' ') {
      options->space_flag = 1;
    }
    (*format)++;
  }
  return result;
}

int get_accuracy(const char** format, OPTIONS* options) {
  int result = count_starting(*format, ".");
  if (result) {
    (*format)++;
    int digit_amount = count_starting(*format, "1234567890");
    for (int i = 0; i < digit_amount; i++) {
      options->has_accuracy = options->has_accuracy * 10;
      options->has_accuracy += **format - '0';
      (*format)++;
    }
    if (!options->has_accuracy) options->zero_accuracy = 1;
  }
  return 0;
}

int get_width(const char** format, OPTIONS* options) {
  int result = count_starting(*format, "1234567890");
  for (int i = 0; i < result; i++) {
    options->has_width = options->has_width * 10;
    options->has_width += **format - '0';
    (*format)++;
  }
  return 0;
}

int get_length(const char** format, OPTIONS* options) {
  int result = count_starting(*format, "hl");
  if (result) {
    if (**format == 'h') options->length = 1;
    if (**format == 'l') options->length = 2;
    (*format)++;
  }
  return result;
}

int get_specificator(const char** format, DATATYPES* types) {
  int result = count_starting(*format, "cdfsu%");
  if (result) {
    switch (**format) {
      case 'c': {
        types->c = 1;
        break;
      }
      case 'd': {
        types->d = 1;
        break;
      }
      case 'f': {
        types->f = 1;
        break;
      }
      case 's': {
        types->s = 1;
        break;
      }
      case 'u': {
        types->u = 1;
        break;
      }
      case '%': {
        types->percent = 1;
        break;
      }
    }
    (*format)++;
  }
  return result;
}

int typer_ch(char** str, OPTIONS options, char x) {
  int counter = 0;
  if (options.left_corner) {
    **str = x;
    (*str)++;
  }
  while (counter < options.has_width - 1) {
    **str = ' ';
    (*str)++;
    counter++;
  }
  if (!options.left_corner) {
    **str = x;
    (*str)++;
  }
  return 0;
}

int typer_int(char** str, OPTIONS options, long long int x) {
  int counter = -1;
  int width_space = 0;
  int accur_space = 0;
  char tmp_buff[100];
  int is_negative = x < 0 ? 1 : 0;
  int width_flag = 0;
  x = x > 0 ? x : -x;

  while (x > 0) {
    counter++;
    int y = x % 10;
    tmp_buff[counter] = '0' + y;
    x = (long long int)(x / 10);
  }
  width_flag = counter + 1;
  while (accur_space < options.has_accuracy - width_flag) {
    counter++;
    accur_space++;
    tmp_buff[counter] = '0';
  }
  width_flag = 0;
  if (is_negative) {
    counter++;
    tmp_buff[counter] = '-';
  } else if (options.show_sign) {
    counter++;
    tmp_buff[counter] = '+';
  } else if (options.space_flag) {
    counter++;
    tmp_buff[counter] = ' ';
  }
  while ((width_space < options.has_width - counter) &&
         (!options.left_corner)) {
    **str = ' ';
    (*str)++;
    width_space++;
    width_flag = 1;
  }
  if (width_flag && (!options.left_corner)) (*str)--;
  accur_space = counter + 1;
  for (; counter >= 0; counter--) {
    **str = tmp_buff[counter];
    (*str)++;
  }
  while ((width_space < options.has_width - accur_space) &&
         (options.left_corner)) {
    **str = ' ';
    (*str)++;
    width_space++;
  }
  return 0;
}

int typer_unsigned_int(char** str, OPTIONS options, long long int x) {
  int counter = -1;
  int width_space = 0;
  int accur_space = 0;
  char tmp_buff[100];
  int width_flag = 0;
  while (x > 0) {
    counter++;
    int y = x % 10;
    tmp_buff[counter] = '0' + y;
    x = (long long int)(x / 10);
  }
  width_flag = counter + 1;
  while (accur_space < options.has_accuracy - width_flag) {
    counter++;
    accur_space++;
    tmp_buff[counter] = '0';
  }
  width_flag = 0;

  while ((width_space < options.has_width - counter) &&
         (!options.left_corner)) {
    **str = ' ';
    (*str)++;
    width_space++;
    width_flag = 1;
  }
  if (width_flag && (!options.left_corner)) (*str)--;
  accur_space = counter + 1;
  for (; counter >= 0; counter--) {
    **str = tmp_buff[counter];
    (*str)++;
  }
  while ((width_space < options.has_width - accur_space) &&
         (options.left_corner)) {
    **str = ' ';
    (*str)++;
    width_space++;
  }
  return 0;
}

int typer_db(char** str, OPTIONS options, double db) {
  OPTIONS new_opt = {0};

  int symb_to_print = 0;
  symb_to_print =
      count_double_symb(db, options.has_accuracy, options.zero_accuracy,
                        ((db < 0) || options.show_sign || options.space_flag));
  while ((options.has_width > symb_to_print) && !options.left_corner) {
    **str = ' ';
    (*str)++;
    symb_to_print++;
  }
  if (db < 0) {
    **str = '-';
    (*str)++;
    db *= -1;
  } else if (options.show_sign) {
    **str = '+';
    (*str)++;
  } else if (options.space_flag) {
    **str = ' ';
    (*str)++;
  }
  int intpart = (int)db;
  double fractpart = db - intpart;

  if (options.zero_accuracy) {
    fractpart *= 100;
    if ((int)fractpart > 50) intpart++;
    typer_int(str, new_opt, intpart);
  } else {
    int accur = options.has_accuracy ? options.has_accuracy : 6;
    typer_int(str, new_opt, intpart);
    **str = '.';
    symb_to_print++;
    (*str)++;
    for (int i = 0; i <= accur + 1; i++) fractpart *= 10;
    long int right_x1 = (long int)fractpart;
    if (right_x1 % 100 > 50) {
      right_x1 = right_x1 / 100 + 1;
    } else {
      right_x1 = right_x1 / 100;
    }
    typer_int(str, new_opt, right_x1);
  }
  while ((options.has_width > symb_to_print - 1) && options.left_corner) {
    **str = ' ';
    (*str)++;
    symb_to_print++;
  }

  return 0;
}

int typer_s(char** str, OPTIONS options, const char* s) {
  int len = (int)s21_strlen(s);
  if (options.has_accuracy) {
    len = options.has_accuracy > len ? len : options.has_accuracy;
  }
  if (options.zero_accuracy) len = 0;
  int count_symb = len;
  while ((options.has_width > count_symb) && !options.left_corner) {
    **str = ' ';
    (*str)++;
    count_symb++;
  }
  for (int i = 0; i < len; i++) {
    **str = s[i];
    (*str)++;
  }
  while ((options.has_width > count_symb) && options.left_corner) {
    **str = ' ';
    (*str)++;
    count_symb++;
  }
  return 0;
}