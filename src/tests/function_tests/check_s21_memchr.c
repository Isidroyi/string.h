//
// Created by Mi on 02.01.2024.
//

#include "check_s21_memchr.h"

#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_normal_string) {
  ck_assert_ptr_eq(s21_memchr(normal_string, 'u', strlen(normal_string)),
                   memchr(normal_string, 'u', strlen(normal_string)));
}
END_TEST

START_TEST(test_no_letter) {
  ck_assert_ptr_null(s21_memchr(normal_string, '^', strlen(normal_string)));
}
END_TEST

START_TEST(test_empty_string) {
  const char *str = "";
  ck_assert_ptr_null(s21_memchr(str, 'a', strlen(str)));
}
END_TEST

START_TEST(test_first_char) {
  ck_assert_ptr_eq(s21_memchr(normal_string, 'L', strlen(normal_string)),
                   memchr(normal_string, 'L', strlen(normal_string)));
}
END_TEST

START_TEST(test_last_char) {
  ck_assert_ptr_eq(s21_memchr(normal_string, '.', strlen(normal_string)),
                   memchr(normal_string, '.', strlen(normal_string)));
}
END_TEST

START_TEST(test_multiple_occurrences) {
  ck_assert_ptr_eq(s21_memchr(large_string, 'o', strlen(large_string)),
                   memchr(large_string, 'o', strlen(large_string)));
}
END_TEST

START_TEST(test_after_max) {
  ck_assert_ptr_null(s21_memchr(normal_string, 'a', 10));
}
END_TEST

START_TEST(test_search_empty_string) {
  const char *str = "";
  char search_char = 'a';

  ck_assert_ptr_null(s21_memchr(str, search_char, strlen(str)));
}
END_TEST

START_TEST(test_search_null_character) {
  const char *str = "Hello, World!";
  char search_char = '\0';

  ck_assert_ptr_eq(s21_memchr(str, search_char, strlen(str)),
                   memchr(str, search_char, strlen(str)));
}
END_TEST

Suite *memchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memchr");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_normal_string);
  tcase_add_test(tc_core, test_no_letter);
  tcase_add_test(tc_core, test_empty_string);
  tcase_add_test(tc_core, test_first_char);
  tcase_add_test(tc_core, test_last_char);
  tcase_add_test(tc_core, test_multiple_occurrences);
  tcase_add_test(tc_core, test_after_max);
  tcase_add_test(tc_core, test_search_empty_string);
  tcase_add_test(tc_core, test_search_null_character);

  suite_add_tcase(s, tc_core);

  return s;
}