#ifndef FILLER
#define FILLER

#define RUN 0
#define SUBMIT 1

#define munit_test(test_name, test)                                            \
  {                                                                            \
      "/" #test_name,         /* name */                                       \
      test,                   /* test */                                       \
      NULL,                   /* setup */                                      \
      NULL,                   /* tear_down */                                  \
      MUNIT_TEST_OPTION_NONE, /* options */                                    \
      NULL                    /* parameters */                                 \
  }

#define munit_case(typ, function_name, body)                                   \
  MunitResult function_name(const MunitParameter params[],                     \
                            void *user_data_or_fixture) {                      \
    body                                                                       \
  }

#define munit_suite(suit_name, tests)                                          \
  {                                                                            \
      "/" #suit_name,         /* name */                                       \
      tests,                  /* test */                                       \
      NULL,                   /* suites */                                     \
      1,                      /* iterations */                                 \
      MUNIT_SUITE_OPTION_NONE /* options */                                    \
  };

#define munit_null_test                                                        \
  {                                                                            \
      NULL,                                                                    \
      NULL,                                                                    \
      NULL,                   /* setup */                                      \
      NULL,                   /* tear_down */                                  \
      MUNIT_TEST_OPTION_NONE, /* options */                                    \
      NULL                    /* parameters */                                 \
  }

#endif // !FILLER
