#include <iostream>

class point {
public:
	int x, y;

	point(int pos_x, int pos_y) {
		x = pos_x;
		y = pos_y;
	}
};

class geometry {
private:
	int num_points;
	point* point_array[100];

public:
	geometry() {
		num_points = 0;
	}

	void add_point(const point& p) {
		point_array[num_points++] = new point(p.x, p.y);
	}

	void print_distance() {
		for (int i = 0; i < num_points; i++) {
			for (int j = i + 1; j < num_points; j++) {
				double distance = sqrt(pow((point_array[i]->x - point_array[j]->x), 2) + pow((point_array[i]->y - point_array[j]->y), 2));
				std::cout << i + 1 << "번째와 " << j + 1 << "번째 점 사이의 거리는 " << distance << "입니다." << std::endl;
			}
		}
	}

	void print_num_meets() {
		int possible_lines = (num_points * (num_points - 1)) / 2;
		int intersect = 0;

		for (int i = 0; i < num_points; i++) {
			for (int j = i + 1; j < num_points; j++) {

				for (int k = 0; k < num_points; k++) {
					if (k == i || k == j) break;
					for (int g = k + 1; g < num_points; g++) {
						if (g == i || g == j) break;
						int f1, f2;
						f1 = ((point_array[i]->x - point_array[j]->x) * (point_array[k]->y - point_array[i]->y)) - ((point_array[i]->y - point_array[j]->y) * (point_array[k]->x - point_array[i]->x));
						f2 = ((point_array[i]->x - point_array[j]->x) * (point_array[g]->y - point_array[i]->y)) - ((point_array[i]->y - point_array[j]->y) * (point_array[g]->x - point_array[i]->x));
						if (f1 * f2 < 0) intersect++;
					}
				}
			}
		}

		std::cout << "교점의 개수는 " << possible_lines - intersect << "개 입니다." << std::endl;
	}
};

int main() {
	point p1(1, 1), p2(1, -1), p3(-1, 1), p4(-1, -1);
	geometry ge;

	ge.add_point(p1);
	ge.add_point(p2);
	ge.add_point(p3);
	ge.add_point(p4);

	ge.print_distance();
	ge.print_num_meets();

	return 0;
}