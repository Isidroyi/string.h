#include <stdlib.h>

#include "function_tests/check_s21_insert.h"
#include "function_tests/check_s21_memchr.h"
#include "function_tests/check_s21_memcmp.h"
#include "function_tests/check_s21_memcpy.h"
#include "function_tests/check_s21_memset.h"
#include "function_tests/check_s21_sprintf.h"
#include "function_tests/check_s21_strchr.h"
#include "function_tests/check_s21_strcspn.h"
#include "function_tests/check_s21_strerror.h"
#include "function_tests/check_s21_strlen.h"
#include "function_tests/check_s21_strncat.h"
#include "function_tests/check_s21_strncmp.h"
#include "function_tests/check_s21_strncpy.h"
#include "function_tests/check_s21_strpbrk.h"
#include "function_tests/check_s21_strrchr.h"
#include "function_tests/check_s21_strstr.h"
#include "function_tests/check_s21_strtok.h"
#include "function_tests/check_s21_to_lower.h"
#include "function_tests/check_s21_to_upper.h"
#include "function_tests/check_s21_trim.h"

int main(void) {
  int number_failed;
  Suite *s_strchr, *s_strlen, *s_memchr, *s_memcmp, *s_memcpy, *s_memset,
      *s_strncat, *s_strncmp, *s_strncpy, *s_strcspn, *s_strerror, *s_strpbrk,
      *s_strrchr, *s_strstr, *s_strtok, *s_sprintf, *s_to_upper, *s_to_lower,
      *s_insert, *s_trim;
  SRunner *sr;

  s_strchr = strchr_suite();
  s_strlen = strlen_suite();
  s_memchr = memchr_suite();
  s_memcmp = memcmp_suite();
  s_memcpy = memcpy_suite();
  s_memset = memset_suite();
  s_strncat = strncat_suite();
  s_strncmp = strncmp_suite();
  s_strncpy = strncpy_suite();
  s_strcspn = strcspn_suite();
  s_strerror = strerror_suite();
  s_strpbrk = strpbrk_suite();
  s_strrchr = strrchr_suite();
  s_strstr = strstr_suite();
  s_strtok = strtok_suite();
  s_sprintf = sprintf_suite();
  s_to_upper = to_upper_suite();
  s_to_lower = to_lower_suite();
  s_insert = insert_suite();
  s_trim = trim_suite();

  sr = srunner_create(s_strchr);
  srunner_add_suite(sr, s_strlen);
  srunner_add_suite(sr, s_memchr);
  srunner_add_suite(sr, s_memcmp);
  srunner_add_suite(sr, s_memcpy);
  srunner_add_suite(sr, s_memset);
  srunner_add_suite(sr, s_strncat);
  srunner_add_suite(sr, s_strncmp);
  srunner_add_suite(sr, s_strncpy);
  srunner_add_suite(sr, s_strcspn);
  srunner_add_suite(sr, s_strerror);
  srunner_add_suite(sr, s_strpbrk);
  srunner_add_suite(sr, s_strrchr);
  srunner_add_suite(sr, s_strstr);
  srunner_add_suite(sr, s_strtok);
  srunner_add_suite(sr, s_sprintf);
  srunner_add_suite(sr, s_to_upper);
  srunner_add_suite(sr, s_to_lower);
  srunner_add_suite(sr, s_insert);
  srunner_add_suite(sr, s_trim);

  srunner_run_all(sr, CK_NORMAL);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}