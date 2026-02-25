#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* ================================================
   স্বয়ং সম্পূর্ণ ক্যালকুলেটর - C প্রোগ্রাম
   ================================================ */

#define PI 3.14159265358979323846

/* ---- রঙিন আউটপুটের জন্য ANSI কোড ---- */
#define RESET   "\033[0m"
#define CYAN    "\033[1;36m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define BOLD    "\033[1m"

/* ---- ইতিহাস সংরক্ষণ ---- */
#define MAX_HISTORY 10

typedef struct {
    char expression[100];
    double result;
} History;

History history[MAX_HISTORY];
int history_count = 0;

void add_history(const char *expr, double result) {
    if (history_count < MAX_HISTORY) {
        strncpy(history[history_count].expression, expr, 99);
        history[history_count].result = result;
        history_count++;
    } else {
        /* পুরনো মুছে নতুন যোগ */
        for (int i = 0; i < MAX_HISTORY - 1; i++)
            history[i] = history[i + 1];
        strncpy(history[MAX_HISTORY - 1].expression, expr, 99);
        history[MAX_HISTORY - 1].result = result;
    }
}

void show_history() {
    if (history_count == 0) {
        printf(YELLOW "  কোনো ইতিহাস নেই।\n" RESET);
        return;
    }
    printf(CYAN "\n  ===== হিসাবের ইতিহাস =====\n" RESET);
    for (int i = 0; i < history_count; i++)
        printf(GREEN "  %d. %s = %.6g\n" RESET, i + 1,
               history[i].expression, history[i].result);
    printf("\n");
}

/* ---- মেনু প্রদর্শন ---- */
void show_menu() {
    printf(CYAN "\n╔══════════════════════════════════════╗\n");
    printf("║       স্বয়ং সম্পূর্ণ ক্যালকুলেটর       ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  " BOLD "--- মৌলিক হিসাব ---" CYAN "                  ║\n");
    printf("║  1.  যোগ          (+)                ║\n");
    printf("║  2.  বিয়োগ        (-)                ║\n");
    printf("║  3.  গুণ          (*)                ║\n");
    printf("║  4.  ভাগ          (/)                ║\n");
    printf("║  5.  ভাগশেষ       (%%)               ║\n");
    printf("║  6.  ঘাত (Power)  (^)               ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  " BOLD "--- বৈজ্ঞানিক হিসাব ---" CYAN "               ║\n");
    printf("║  7.  বর্গমূল      (√x)              ║\n");
    printf("║  8.  লগারিদম     (log10)            ║\n");
    printf("║  9.  প্রাকৃতিক লগ (ln)              ║\n");
    printf("║  10. Sin(degree)                     ║\n");
    printf("║  11. Cos(degree)                     ║\n");
    printf("║  12. Tan(degree)                     ║\n");
    printf("║  13. ফ্যাক্টরিয়াল (n!)              ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  " BOLD "--- রূপান্তর ---" CYAN "                       ║\n");
    printf("║  14. ডিগ্রি → রেডিয়ান               ║\n");
    printf("║  15. রেডিয়ান → ডিগ্রি               ║\n");
    printf("║  16. সেলসিয়াস → ফারেনহাইট          ║\n");
    printf("║  17. ফারেনহাইট → সেলসিয়াস          ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  18. হিসাবের ইতিহাস দেখুন           ║\n");
    printf("║  0.  বের হন (Exit)                   ║\n");
    printf("╚══════════════════════════════════════╝\n" RESET);
    printf(YELLOW "  আপনার পছন্দ লিখুন: " RESET);
}

/* ---- ফ্যাক্টরিয়াল ---- */
long long factorial(int n) {
    if (n < 0)  return -1;
    if (n == 0) return 1;
    long long result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

/* ---- দুটি সংখ্যা ইনপুট নেওয়া ---- */
void get_two_numbers(double *a, double *b) {
    printf(YELLOW "  প্রথম সংখ্যা: " RESET);
    while (scanf("%lf", a) != 1) {
        printf(RED "  ভুল ইনপুট! আবার দিন: " RESET);
        while (getchar() != '\n');
    }
    printf(YELLOW "  দ্বিতীয় সংখ্যা: " RESET);
    while (scanf("%lf", b) != 1) {
        printf(RED "  ভুল ইনপুট! আবার দিন: " RESET);
        while (getchar() != '\n');
    }
}

/* ---- একটি সংখ্যা ইনপুট নেওয়া ---- */
void get_one_number(double *a) {
    printf(YELLOW "  সংখ্যা দিন: " RESET);
    while (scanf("%lf", a) != 1) {
        printf(RED "  ভুল ইনপুট! আবার দিন: " RESET);
        while (getchar() != '\n');
    }
}

/* ============ মূল প্রোগ্রাম ============ */
int main() {
    int choice;
    double num1, num2, result;
    char expr[100];

    printf(GREEN "\n  ক্যালকুলেটরে স্বাগতম!\n" RESET);

    while (1) {
        show_menu();

        if (scanf("%d", &choice) != 1) {
            printf(RED "  ভুল ইনপুট!\n" RESET);
            while (getchar() != '\n');
            continue;
        }

        if (choice == 0) {
            printf(GREEN "\n  ধন্যবাদ! আবার আসবেন।\n\n" RESET);
            break;
        }

        switch (choice) {

            /* -------- মৌলিক হিসাব -------- */
            case 1:
                get_two_numbers(&num1, &num2);
                result = num1 + num2;
                snprintf(expr, 100, "%.6g + %.6g", num1, num2);
                printf(GREEN "  ফলাফল = %.6g\n" RESET, result);
                add_history(expr, result);
                break;

            case 2:
                get_two_numbers(&num1, &num2);
                result = num1 - num2;
                snprintf(expr, 100, "%.6g - %.6g", num1, num2);
                printf(GREEN "  ফলাফল = %.6g\n" RESET, result);
                add_history(expr, result);
                break;

            case 3:
                get_two_numbers(&num1, &num2);
                result = num1 * num2;
                snprintf(expr, 100, "%.6g * %.6g", num1, num2);
                printf(GREEN "  ফলাফল = %.6g\n" RESET, result);
                add_history(expr, result);
                break;

            case 4:
                get_two_numbers(&num1, &num2);
                if (num2 == 0.0) {
                    printf(RED "  ত্রুটি! শূন্য দিয়ে ভাগ করা যাবে না।\n" RESET);
                } else {
                    result = num1 / num2;
                    snprintf(expr, 100, "%.6g / %.6g", num1, num2);
                    printf(GREEN "  ফলাফল = %.6g\n" RESET, result);
                    add_history(expr, result);
                }
                break;

            case 5:
                get_two_numbers(&num1, &num2);
                if ((int)num2 == 0) {
                    printf(RED "  ত্রুটি! শূন্য দিয়ে ভাগশেষ হয় না।\n" RESET);
                } else {
                    result = (double)((int)num1 % (int)num2);
                    snprintf(expr, 100, "%.6g %% %.6g", num1, num2);
                    printf(GREEN "  ফলাফল = %.6g\n" RESET, result);
                    add_history(expr, result);
                }
                break;

            case 6:
                get_two_numbers(&num1, &num2);
                result = pow(num1, num2);
                snprintf(expr, 100, "%.6g ^ %.6g", num1, num2);
                printf(GREEN "  ফলাফল = %.6g\n" RESET, result);
                add_history(expr, result);
                break;

            /* -------- বৈজ্ঞানিক হিসাব -------- */
            case 7:
                get_one_number(&num1);
                if (num1 < 0) {
                    printf(RED "  ত্রুটি! ঋণাত্মক সংখ্যার বর্গমূল হয় না।\n" RESET);
                } else {
                    result = sqrt(num1);
                    snprintf(expr, 100, "√%.6g", num1);
                    printf(GREEN "  ফলাফল = %.6g\n" RESET, result);
                    add_history(expr, result);
                }
                break;

            case 8:
                get_one_number(&num1);
                if (num1 <= 0) {
                    printf(RED "  ত্রুটি! শূন্য বা ঋণাত্মক সংখ্যার লগ হয় না।\n" RESET);
                } else {
                    result = log10(num1);
                    snprintf(expr, 100, "log10(%.6g)", num1);
                    printf(GREEN "  ফলাফল = %.6g\n" RESET, result);
                    add_history(expr, result);
                }
                break;

            case 9:
                get_one_number(&num1);
                if (num1 <= 0) {
                    printf(RED "  ত্রুটি! শূন্য বা ঋণাত্মক সংখ্যার ln হয় না।\n" RESET);
                } else {
                    result = log(num1);
                    snprintf(expr, 100, "ln(%.6g)", num1);
                    printf(GREEN "  ফলাফল = %.6g\n" RESET, result);
                    add_history(expr, result);
                }
                break;

            case 10:
                get_one_number(&num1);
                result = sin(num1 * PI / 180.0);
                snprintf(expr, 100, "sin(%.6g°)", num1);
                printf(GREEN "  ফলাফল = %.6g\n" RESET, result);
                add_history(expr, result);
                break;

            case 11:
                get_one_number(&num1);
                result = cos(num1 * PI / 180.0);
                snprintf(expr, 100, "cos(%.6g°)", num1);
                printf(GREEN "  ফলাফল = %.6g\n" RESET, result);
                add_history(expr, result);
                break;

            case 12:
                get_one_number(&num1);
                if (fmod(fabs(num1) - 90.0, 180.0) == 0.0) {
                    printf(RED "  ত্রুটি! এই কোণের Tan অসংজ্ঞায়িত।\n" RESET);
                } else {
                    result = tan(num1 * PI / 180.0);
                    snprintf(expr, 100, "tan(%.6g°)", num1);
                    printf(GREEN "  ফলাফল = %.6g\n" RESET, result);
                    add_history(expr, result);
                }
                break;

            case 13: {
                int n;
                printf(YELLOW "  পূর্ণ সংখ্যা দিন: " RESET);
                if (scanf("%d", &n) != 1 || n < 0) {
                    printf(RED "  ত্রুটি! ধনাত্মক পূর্ণ সংখ্যা দিন।\n" RESET);
                    while (getchar() != '\n');
                } else if (n > 20) {
                    printf(RED "  ত্রুটি! ২০-এর বেশি ফ্যাক্টরিয়াল অনেক বড়।\n" RESET);
                } else {
                    long long fact = factorial(n);
                    snprintf(expr, 100, "%d!", n);
                    printf(GREEN "  ফলাফল = %lld\n" RESET, fact);
                    add_history(expr, (double)fact);
                }
                break;
            }

            /* -------- রূপান্তর -------- */
            case 14:
                get_one_number(&num1);
                result = num1 * PI / 180.0;
                snprintf(expr, 100, "%.6g° → রেডিয়ান", num1);
                printf(GREEN "  ফলাফল = %.6g রেডিয়ান\n" RESET, result);
                add_history(expr, result);
                break;

            case 15:
                get_one_number(&num1);
                result = num1 * 180.0 / PI;
                snprintf(expr, 100, "%.6g rad → ডিগ্রি", num1);
                printf(GREEN "  ফলাফল = %.6g°\n" RESET, result);
                add_history(expr, result);
                break;

            case 16:
                get_one_number(&num1);
                result = (num1 * 9.0 / 5.0) + 32.0;
                snprintf(expr, 100, "%.6g°C → °F", num1);
                printf(GREEN "  ফলাফল = %.6g°F\n" RESET, result);
                add_history(expr, result);
                break;

            case 17:
                get_one_number(&num1);
                result = (num1 - 32.0) * 5.0 / 9.0;
                snprintf(expr, 100, "%.6g°F → °C", num1);
                printf(GREEN "  ফলাফল = %.6g°C\n" RESET, result);
                add_history(expr, result);
                break;

            /* -------- ইতিহাস -------- */
            case 18:
                show_history();
                break;

            default:
                printf(RED "  অবৈধ পছন্দ! ০ থেকে ১৮-এর মধ্যে দিন।\n" RESET);
        }
    }

    return 0;
}

