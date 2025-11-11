#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>


using namespace std;

class Polygon
{
private:
    map<char, pair<double, double>> Vertices;          
             
    string Type;

public:
    map<char, map<char, double>> Edges;
    map<char, pair<double, double>> get_vertices() { return Vertices; }
    map<char, map<char, double>> get_edges() { return Edges; }
    string get_type() { return Type; }

    double calcDistance(pair<double, double> p1, pair<double, double> p2)
    {
        return hypot(p2.first - p1.first, p2.second - p1.second);
    }

    map<char, map<char, double>> GetConvex(map<char ,pair<double,double>> thePoints)
    {
        vector<pair<char, pair<double, double>>> points;
        for (auto& p : thePoints)
            points.push_back(p);

        int n = points.size();
        if (n < 3)
        {
            cout << "A polygon needs at least 3 points.\n";
            return {};
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    char a = points[i].first;
                    char b = points[j].first;
                    double dist = calcDistance(points[i].second, points[j].second);
                    Edges[a][b] = dist;
                }
            }
        }
        return Edges;
    }

    int crossProduct(pair<double, double> O, pair<double, double> A, pair<double, double> B)
    {
        return (A.first - O.first) * (B.second - O.second)
        - (A.second - O.second) * (B.first - O.first);
    }

    vector<pair<double, double>> getConvexHull()
    {
        vector<pair<double, double>> pts;
        for (auto& v : Vertices)
            pts.push_back(v.second);

        int n = pts.size();
        if (n <= 3) return pts;

        sort(pts.begin(), pts.end(), [](auto& a, auto& b)
             {
                 return (a.second < b.second) ||
                        (a.second == b.second && a.first < b.first);
             });

        pair<double, double> pivot = pts[0];

        sort(pts.begin() + 1, pts.end(), [&](auto& a, auto& b)
             {
                 int cp = crossProduct(pivot, a, b);
                 if (cp == 0)
                     return hypot(a.first - pivot.first, a.second - pivot.second)
                            < hypot(b.first - pivot.first, b.second - pivot.second);
                 return cp > 0;
             });

        vector<pair<double, double>> hull;
        for (auto& p : pts)
        {
            while (hull.size() >= 2 &&
                   crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], p) <= 0)
                hull.pop_back();
            hull.push_back(p);
        }

        return hull;
    }


    bool onSegment(pair<double,double> p, pair<double,double> q, pair<double,double> r)
    {
        return (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
                q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second));
    }

    bool segmentsIntersect(pair<double, double> p1, pair<double, double> p2,
                           pair<double, double> p3, pair<double, double> p4)
    {
        auto orientation = [](pair<double, double> a, pair<double, double> b, pair<double, double> c) {
            double val = (b.second - a.second) * (c.first - b.first) -
                         (b.first - a.first) * (c.second - b.second);
            if (fabs(val) < 1e-9) return 0; 
            return (val > 0) ? 1 : 2; 
        };

        int o1 = orientation(p1, p2, p3);
        int o2 = orientation(p1, p2, p4);
        int o3 = orientation(p3, p4, p1);
        int o4 = orientation(p3, p4, p2);

        
        if (o1 != o2 && o3 != o4)
            return true;

        
        if (o1 == 0 && onSegment(p1, p3, p2)) return true;
        if (o2 == 0 && onSegment(p1, p4, p2)) return true;
        if (o3 == 0 && onSegment(p3, p1, p4)) return true;
        if (o4 == 0 && onSegment(p3, p2, p4)) return true;

        return false;
    }


    bool visible(char a, char b)
    {
        pair<double, double> A = Vertices[a];
        pair<double, double> B = Vertices[b];

        auto V = GetConcaveHull();
        for (size_t i = 0; i < V.size(); i++)
        {
            char c = V[i].first;
            char d = V[i].second;

            if (c == a || c == b || d == a || d == b) continue;

            if (segmentsIntersect(A, B, Vertices[c], Vertices[d]))
                return false;
        }
        return true;
    }

    void repair()
    {
        vector<pair<char, pair<int, int>>> points;
        for (auto& p : Vertices)
            points.push_back(p);

        int n = points.size();
        if (n < 4) return;

        bool changed = true;
        while (changed)
        {
            changed = false;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 2; j < n - 1; j++)
                {
                    if (segmentsIntersect(points[i].second, points[i + 1].second,
                                          points[j].second, points[j + 1].second))
                    {
                        reverse(points.begin() + i + 1, points.begin() + j + 1);
                        changed = true;
                    }
                }
            }
        }

        Vertices.clear();
        for (auto& p : points)
            Vertices[p.first] = p.second;

        Edges.clear();
        for (int i = 0; i < n; i++)
        {
            char a = points[i].first;
            char b = points[(i + 1) % n].first;
            double dist = calcDistance(points[i].second, points[(i + 1) % n].second);
            Edges[a][b] = dist;
            Edges[b][a] = dist;
        }
    }

    int getIndexByChar(const vector<pair<char, pair<double, double>>>& V, char target)
    {
        for (size_t i = 0; i < V.size(); i++)
        {
            if (V[i].first == target)
                return i;
        }
        return -1;
    }


    vector<pair<char, char>> get_point()
    {
        vector<pair<char, pair<double, double>>> V;
        for (auto& p : Vertices)
            V.push_back(p);

        vector<pair<char,char>> E ;
        int n = V.size();
        if (n < 3)
            return E;

        pair<char,pair<double, double>> pivot = V[0];

        for (int i = 0; i < n; i++)
            if (V[i].second.second < pivot.second.second ||
                (V[i].second.second == pivot.second.second && V[i].second.first < pivot.second.first))
                pivot = V[i];
        auto x = find(V.begin(),V.end(),pivot);
        V.erase(x);
        vector<pair<char, double>> S;
        double t ;
        for (int i = 0; i < n-1; i++)
        {
            if((V[i].second.first - pivot.second.first) == 0)
            {
                t = 90;
                S.push_back({V[i].first, t});
            }
            else if ((V[i].second.second - pivot.second.second) /(V[i].second.first - pivot.second.first) < 0)
            {
                t = atan((V[i].second.second - pivot.second.second) /(V[i].second.first - pivot.second.first));
                S.push_back({V[i].first, t * 180 * 7/22 + 180 });
            }
            else
            {
                t = atan((V[i].second.second - pivot.second.second) /(V[i].second.first - pivot.second.first));
                S.push_back({V[i].first, t * 180 * 7/22 });
            }
        }

        sort(S.begin(), S.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });
        for (size_t j = 0; j < S.size() - 2; j++)
        {
            int i1 = getIndexByChar(V, S[j].first);
            int i2 = getIndexByChar(V, S[j + 1].first);
            int i3 = getIndexByChar(V, S[j + 2].first);

            if (crossProduct(V[i1].second, V[i2].second, V[i3].second) < 0)
                E.push_back({V[i1].first,V[i3].first});


        }

        return E;
    }

    vector<pair<char,char>> GetConcaveHull()
    {
        vector<pair<char, pair<double, double>>> V;
        for (auto& p : Vertices)
            V.push_back(p);

        vector<pair<char,char>> E ;
        int n = V.size();
        if (n < 3)
            return E;

        pair<char,pair<double, double>> pivot = V[0];

        for (int i = 0; i < n; i++)
            if (V[i].second.second < pivot.second.second ||
                (V[i].second.second == pivot.second.second && V[i].second.first < pivot.second.first))
                pivot = V[i];
        auto x = find(V.begin(),V.end(),pivot);
        V.erase(x);
        vector<pair<char, double>> S;
        double t ;
        for (int i = 0; i < n-1; i++)
        {
            if((V[i].second.first - pivot.second.first) == 0)
            {
                t = 90;
                S.push_back({V[i].first, t});
            }
            else if ((V[i].second.second - pivot.second.second) /(V[i].second.first - pivot.second.first) < 0)
            {
                t = atan((V[i].second.second - pivot.second.second) /(V[i].second.first - pivot.second.first));
                S.push_back({V[i].first, t * 180 * 7/22 + 180 });
            }
            else
            {
                t = atan((V[i].second.second - pivot.second.second) /(V[i].second.first - pivot.second.first));
                S.push_back({V[i].first, t * 180 * 7/22 });
            }
        }

        sort(S.begin(), S.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });

        E.push_back({pivot.first,S[0].first});

        for (size_t j = 0; j < S.size() - 1; j++)
        {
            E.push_back({S[j].first,S[j+1].first});
        }

        E.push_back({S[S.size()-1].first,pivot.first});
        return E;
    }

    void GetConcave(map<char ,pair<double,double>> thePoints)
    {
        Vertices=thePoints;
        vector<pair<char, pair<double, double>>> V;

        for (auto& p : thePoints)
            V.push_back(p);

        int n = V.size();

        vector<pair<char,char>> E = get_point();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && visible(V[i].first, V[j].first))
                {
                    char c1 = V[i].first;
                    char c2 = V[j].first;
                    double dist = calcDistance(V[i].second, V[j].second);
                    Edges[c1][c2] = dist;
                }
            }
        }
        for(size_t i=0 ; i<E.size() ; i++)
        {
            Edges[E[i].first].erase(E[i].second);
            Edges[E[i].second].erase(E[i].first);
        }
    }

};
