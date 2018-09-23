#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct point2d {
	int x,y;

};

struct point3d {
	int x,y,z;

};

void closestpair2d(struct point2d *,struct point2d *, int);
void closestpair3d(struct point3d *,struct point3d *,int);
void euclideanMST(struct point2d **,struct point2d *,int);

double dist(struct point2d p1, struct point2d p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
			(p1.y - p2.y)*(p1.y - p2.y) );
}
double dist3(struct point3d p1, struct point3d p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
			(p1.y - p2.y)*(p1.y - p2.y)  + (p1.z - p2.z)*(p1.z - p2.z));
}
int main()
{
	struct point2d *points,close2d[2],**mst;
	struct point3d *plane,close3d[2];
	int i,n,m;
	scanf("%d",&n);
	points = (struct point2d *)malloc(n*sizeof(struct point2d));
	for(i=0;i<n;i++)
		scanf("%d%d",&(points[i].x),&(points[i].y));
	qsort(points, n, sizeof(struct point2d), cmpX);
	scanf("%d",&m);
	plane = (struct point3d *)malloc(m*sizeof(struct point3d));
	for(i=0;i<m;i++)
		scanf("%d%d%d",&(plane[i].x),&(plane[i].y),&(plane[i].z));
	closestpair2d(close2d,points,n);
	printf("(%d, %d), and (%d, %d) dis=%f\n", close2d[0].x, close2d[0].y, close2d[1].x, close2d[1].y,dist(close2d[0], close2d[1]));
	closestpair3d(close3d,plane,m);
	printf("(%d, %d, %d), and (%d, %d, %d) dis=%f\n", close3d[0].x, close3d[0].y, close3d[0].z, close3d[1].x, close3d[1].y, close3d[1].z, dist3(close3d[0], close3d[1]));
	mst = (struct point2d **)malloc((n-1)*sizeof(struct point2d *));
	for(i=0;i<n;i++)
		mst[i]=(struct point2d *)malloc(2*sizeof(struct point2d));
	euclideanMST(mst,points,n);
	return 0;

}

double min(double x, double y)
{
	return (x < y)? x : y;
}
void bruteForce2(struct point2d P[], int n, struct point2d *p1, struct point2d *p2)
{
	double mn = 1e8;
	int i,j;
	for (i = 0; i < n; ++i)
		for (j = i+1; j < n; ++j)
			if (dist(P[i], P[j]) < mn) {
				mn = dist(P[i], P[j]);
				(*p1).x = P[i].x;
				(*p1).y = P[i].y;
				(*p2).x = P[j].x;
				(*p2).y = P[j].y;

			}


}
void bruteForce3(struct point3d P[], int n, struct point3d *p1, struct point3d *p2)
{
	double mn = 1e8;
	int i,j;
	for (i = 0; i < n; ++i)
		for (j = i+1; j < n; ++j)
			if (dist3(P[i], P[j]) < mn) {
				mn = dist3(P[i], P[j]);
				(*p1).x = P[i].x;
				(*p1).y = P[i].y;
				(*p1).z = P[i].z;

				(*p2).x = P[j].x;
				(*p2).y = P[j].y;
				(*p2).z = P[j].z;

			}


}
int compareY(const void* a, const void* b)
{
	struct point2d *p1 = (struct point2d *)a , *p2 = (struct point2d *)b;
	return (p1->y - p2->y);
}

int cmpX(const void* p1, const void* p2)
{
	struct Point *a, *b;
	a = (struct point2d*) p1;
	b = (struct point2d*) p2;
	return (a->x - b->x);
}

double stripPoints(struct point2d strip[], int size, double d, struct point2d *p1, struct point2d *p2)
{
	double mn = d;  // Initialize the minimum distance as d

	qsort(strip, size, sizeof(struct point2d), compareY);

	// Pick all points one by one and try the next points 
	// till the difference between y's is smaller than d.
	int i,j;
	for (i = 0; i < size; ++i)
		for (j = i+1; j < size && (strip[j].y - strip[i].y) < mn; ++j)
			if (dist(strip[i],strip[j]) < mn) {
				mn = dist(strip[i], strip[j]);
				(*p1).x = strip[i].x;
				(*p1).y = strip[i].y;
				(*p2).x = strip[j].x;
				(*p2).y = strip[j].y;
			}

	return mn;
}
double stripPoints3(struct point3d strip[], int size, double d, struct point3d *p1, struct point3d *p2)
{
	double mn = d;  // Initialize the minimum distance as d

	//qsort(strip, size, sizeof(struct point2d), compareY);

	// Pick all points one by one and try the next points 
	// till the difference between y's is smaller than d.
	int i,j;
	for (i = 0; i < size; ++i)
		for (j = i+1; j < size; ++j)
			if (dist3(strip[i],strip[j]) < mn) {
				mn = dist3(strip[i], strip[j]);
				(*p1).x = strip[i].x;
				(*p1).y = strip[i].y;
				(*p1).z = strip[i].z;

				(*p2).x = strip[j].x;
				(*p2).y = strip[j].y;
				(*p2).z = strip[j].z;
			}

	return mn;
}
void closestpair2d(struct point2d *close2d, struct point2d *points, int n)
{
	struct point2d ptemp1, ptemp2, ptemp3, ptemp4, c2d1[2], c2d2[2];

	// use brute force when there are not enough points
	if (n <= 3)
	{
		bruteForce2(points, n, &ptemp1, &ptemp2);
		close2d[0] = ptemp1;
		close2d[1] = ptemp2;
		return;
	}

	// mid point
	int mid = n/2;
	struct point2d midPoint = points[mid];

	// calculate the smallest distance 
	// dl: left of mid point 
	// dr: right side of the mid point
	closestpair2d(c2d1, points, mid);
	closestpair2d(c2d2, points + mid, n-mid);

	double dl,dr;
	dl = dist(c2d1[0], c2d1[1]);
	dr = dist(c2d2[0], c2d2[1]);
	// assign the pair that has smaller distance
	if(dl < dr) {
		close2d[0].x = c2d1[0].x; 
		close2d[0].y = c2d1[0].y;
		close2d[1].x = c2d1[1].x; 
		close2d[1].y = c2d1[1].y;
	}
	else {
		close2d[0].x = c2d2[0].x; 
		close2d[0].y = c2d2[0].y;
		close2d[1].x = c2d2[1].x; 
		close2d[1].y = c2d2[1].y;
	}

	double dmin = min(dl, dr);

	struct point2d strip[n];
	int j = 0;
	int i;
	for (i = 0; i < n; i++)
		if (abs(points[i].x - midPoint.x) < dmin)
			strip[j++] = points[i];

	double dmin_strip = stripPoints(strip, j, dmin, &ptemp1, &ptemp2);
	if(dmin_strip < dmin) {
		close2d[0].x = ptemp1.x; 
		close2d[0].y = ptemp1.y;
		close2d[1].x = ptemp2.x; 
		close2d[1].y = ptemp2.y;
	}

}

void closestpair3d(struct point3d *close3d, struct point3d *plane,int m)
{

	struct point3d ptemp1, ptemp2, ptemp3, ptemp4, c3d1[2], c3d2[2];

	// use brute force when there are not enough points
	if (m <= 3)
	{
		bruteForce3(plane, m, &ptemp1, &ptemp2);
		close3d[0] = ptemp1;
		close3d[1] = ptemp2;
		return;
	}

	// mid point
	int mid = m/2;
	struct point3d midPoint = plane[mid];

	// calculate the smallest distance 
	// dl: left of mid point 
	// dr: right side of the mid point
	closestpair3d(c3d1, plane, mid);
	closestpair3d(c3d2, plane + mid, m-mid);

	double dl,dr;
	dl = dist3(c3d1[0], c3d1[1]);
	dr = dist3(c3d2[0], c3d2[1]);
	// assign the pair that has smaller distance
	if(dl < dr) {
		close3d[0].x = c3d1[0].x; 
		close3d[0].y = c3d1[0].y;
		close3d[0].z = c3d1[0].z;

		close3d[1].x = c3d1[1].x; 
		close3d[1].y = c3d1[1].y;
		close3d[1].z = c3d1[1].z;
	}
	else {
		close3d[0].x = c3d2[0].x; 
		close3d[0].y = c3d2[0].y;
		close3d[0].z = c3d2[0].z;

		close3d[1].x = c3d2[1].x; 
		close3d[1].y = c3d2[1].y;
		close3d[1].z = c3d2[1].z;
	}

	double dmin = min(dl, dr);

	struct point3d strip[m];
	int j = 0;
	int i;
	//change for 3d
	for (i = 0; i < m; i++)
		if (dist3(plane[i] , midPoint) < dmin)
			strip[j++] = plane[i];

	double dmin_strip = stripPoints3(strip, j, dmin, &ptemp1, &ptemp2);
	if(dmin_strip < dmin) {
		close3d[0].x = ptemp1.x; 
		close3d[0].y = ptemp1.y;
		close3d[0].z = ptemp1.z;

		close3d[1].x = ptemp2.x; 
		close3d[1].y = ptemp2.y;
		close3d[0].z = ptemp2.z;
	}

	// find out the closest pair of points among the points in "plane" and store them in the array close3d */

}
int findset(int par[], int i)
{
	while(i != par[i])
	{
		par[i] = par[par[i]];
		i = par[i];
	}
	return i;
}
void euclideanMST(struct point2d **mst,struct point2d *points,int n)
{
	/* find out the Euclidean MST and store the MST in 2d-array mst.
	 *      Each of the n-1 edges are store by storing it's two endpoints.
	 *        
	 */
	int par[n];
	int i, j;
	for(i=0;i<n;++i)
	{
		par[i] = i;
	}
	int t = n-1;
	int sz = 0;
	while(t--)
	{
		double mind = 1e8;
		int b,a, pi,pj;
		for(i=0;i<n;++i)
		{
			for(j=i+1;j<n;++j)
			{
				pi = findset(par, i);
				pj = findset(par, j);
				if(dist(points[i], points[j]) < mind && pi != pj)
				{
					a = i;
					b = j;
					mind = dist(points[i], points[j]);
				}
			}
		}
		int pa,pb;
		pa = findset(par,a);
		pb = findset(par,b);
		par[pa] = pb;
		mst[sz][0].x = points[a].x;
		mst[sz][0].y = points[a].y;
		mst[sz][1].x = points[b].x;
		mst[sz][1].y = points[b].y;
		sz++;
	}
	printf("Euclidean MST\n");
	for(i=0;i<n-1;++i)
	{
		printf("(%d, %d) ---- (%d, %d)\n", mst[i][0].x, mst[i][0].y, mst[i][1].x, mst[i][1].y);
	}
}