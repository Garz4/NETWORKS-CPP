#ifndef TEST_H_
#define TEST_H_

#define EXPECT_EQUAL(lhs, rhs) \
  if (lhs != rhs) { \
    fprintf(stderr, "Test error: Not equal.\n"); \
    exit(0); \
  }

#endif // TEST_H_
