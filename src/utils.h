#ifndef UTILS_H
#define UTILS_H

typedef struct {
  int left_corner;
  int show_sign;
  int space_flag;
  int has_width;
  int has_accuracy;
  int length;
  int zero_accuracy;
} OPTIONS;
typedef struct {
  int c;
  int d;
  int f;
  int s;
  int u;
  int percent;
} DATATYPES;

int get_number_length(int number);  // Определяет длину числа
char* int_to_str(int number);  // Преобразует число int в строку
int count_double_symb(double x, int accur, int zero_accur, int need_symb);
int count_starting(const char* str1, const char* str2);
int get_flags(const char** format, OPTIONS* options);
int get_accuracy(const char** format, OPTIONS* options);
int get_width(const char** format, OPTIONS* options);
int get_length(const char** format, OPTIONS* options);
int get_specificator(const char** format, DATATYPES* types);
int typer_ch(char** str, OPTIONS options, char x);
int typer_int(char** str, OPTIONS options, long long int x);
int typer_unsigned_int(char** str, OPTIONS options, long long int x);
int typer_db(char** str, OPTIONS options, double db);
int typer_s(char** str, OPTIONS options, const char* s);

#endif