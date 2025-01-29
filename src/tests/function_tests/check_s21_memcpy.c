//
// Created by Mi on 02.01.2024.
//

#include "check_s21_memcpy.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_equal_strings) {
  const char *source = "Hello, World!";
  char s21_destination[20];
  char destination[20];

  ck_assert_str_eq(s21_memcpy(s21_destination, source, strlen(source) + 1),
                   memcpy(destination, source, strlen(source) + 1));
}
END_TEST

START_TEST(test_empty_string) {
  const char *source = "";
  char s21_destination[10];
  char destination[10];

  ck_assert_str_eq(s21_memcpy(s21_destination, source, 1),
                   memcpy(destination, source, 1));
}
END_TEST

START_TEST(test_strings_with_null_terminator) {
  const char *source = "Hello";
  char s21_destination[10];
  char destination[10];

  ck_assert_str_eq(s21_memcpy(s21_destination, source, strlen(source) + 1),
                   memcpy(destination, source, strlen(source) + 1));
}
END_TEST

START_TEST(test_binary_data) {
  const char *source = "\x01\x02\x03\x04";
  char s21_destination[4];
  char destination[4];

  ck_assert_mem_eq(s21_memcpy(s21_destination, source, 4),
                   memcpy(destination, source, 4), 4);
}
END_TEST

START_TEST(test_overlap) {
  const char source[] = "Hello, World!";
  char s21_destination[20];
  char destination[20];

  ck_assert_str_eq(s21_memcpy(s21_destination + 5, source, strlen(source) + 1),
                   memcpy(destination + 5, source, strlen(source) + 1));
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memcpy");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_equal_strings);
  tcase_add_test(tc_core, test_empty_string);
  tcase_add_test(tc_core, test_strings_with_null_terminator);
  tcase_add_test(tc_core, test_binary_data);
  tcase_add_test(tc_core, test_overlap);

  suite_add_tcase(s, tc_core);

  return s;
}