#include <iostream>
#include <cmath>

int main() {
    int num_roof = 0;
    double total_time = 0;
    scanf("%d", &num_roof);
    for (int i = 0; i < num_roof; i++) {
        double x, y;
        int num_people = 0;
        scanf("%lf%lf%d", &x, &y, &num_people);
        double distance = sqrt(x*x + y*y);
        double time_one_way = distance / 50;
        double time_get_on = num_people * 1;
        double time_get_off = num_people * 0.5;
        total_time += 2*time_one_way + time_get_off + time_get_on;
    }
    printf("%d\n", int(total_time + 1));
    return 0;
}
