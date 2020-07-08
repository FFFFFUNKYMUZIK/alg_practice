/*
Note:

Assume that the total area is never beyond the maximum possible value of int.
*/

#if 0

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // Lec1 : (A,B), (C,B), (C,D), (A,D) (CCW)
        // Lec2 : (E,F), (G,F), (G,H), (E,H) (CCW)
        long long Al=A, Bl=B, Cl=C, Dl=D, El=E, Fl=F, Gl=G, Hl=H;
        long long area = (Cl-Al)*(Dl-Bl) + (Gl-El)*(Hl-Fl) -/*intersection*/max(min(min(Cl-El, Gl-Al), min(Cl-Al, Gl-El)), 0LL) * max(min(min(Dl-Fl, Hl-Bl), min(Dl-Bl, Hl-Fl)), 0LL);     
        return  (int)area;     
    }
};

#else

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // Lec1 : (A,B), (C,B), (C,D), (A,D) (CCW)
        // Lec2 : (E,F), (G,F), (G,H), (E,H) (CCW)
        if (C<=E || G<=A || B>=H || D<=F) return (C-A)*(D-B) + (G-E)*(H-F);
        return  (C-A)*(D-B) - /*intersection*/max(min(C, G) - max(A,E), 0)*max(min(D, H) - max(B,F), 0)  + (G-E)*(H-F);     
    }
};

#endif