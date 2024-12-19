#include <stdio.h>
#include <math.h>
#define pi 3.141592653589793

struct pointcarte{double x, y;};

struct pointpolar{double r, th;};

void readcar(struct pointcarte *ptc)
{
    printf("Δώσε τις καρτεσιανές τιμές του σημείου, x και y:\n");
    scanf("%lf %lf", &(ptc->x), &(ptc->y));
}

void readpol(struct pointpolar *ptp)
{
    printf("Δώσε τις πολίκες τιμές του σημείου, r και th [deg]:\n");
    scanf("%lf %lf", &(ptp->r), &(ptp->th));
}

struct pointpolar cartopol(struct pointcarte ptc)
{
    struct pointpolar ptp;
    ptp.r = sqrt(pow(ptc.x, 2)+pow(ptc.y, 2));
    ptp.th = atan2(ptc.y, ptc.x);

    return ptp;
}

struct pointcarte poltocar(struct pointpolar ptp)
{
    struct pointcarte ptc;
    ptc.x = ptp.r * cos(ptp.th);
    ptc.y = ptp.r * sin(ptp.th);
    return ptc;
}

void printcar(struct pointcarte ptc)
{
    printf("(x,y)=(%.2f,%.2f)\n", ptc.x, ptc.y);
}

void printpol(struct pointpolar ptp, char c)
{
    if(c=='r')
        printf("(r,th)=(%.2f,%.2f)[rad]\n", ptp.r, ptp.th);
    else
        printf("(r,th)=(%.2f,%.2f)[deg]\n", ptp.r, ptp.th*180/pi);
}

void process()
{
    struct pointpolar ptp;
    struct pointcarte ptc;
    readcar(&ptc);
    printcar(ptc);
    ptp = cartopol(ptc);
    printpol(ptp, 'r');
    printpol(ptp, 'd');
    readpol(&ptp);
    poltocar(ptp);
    printcar(ptc);
}

int main(void)
{
    process();
}
