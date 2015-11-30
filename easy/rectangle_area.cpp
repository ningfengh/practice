class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
			int area1,area2,area_overlap;
			area1 = (C-A)*(D-B);
			area2 = (G-E)*(H-F);
			area_overlap = (min(C,G)-max(A,E))*(min(D,H)-max(B,F));
			if (area_overlap<0) area_overlap=0;
			return area1-area_overlap+area2;
    }
};