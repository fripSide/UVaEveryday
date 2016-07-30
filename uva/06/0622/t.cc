//#define LOCAL
//#define TESTING
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int rspace[15][15], bspace[15][15], rqp[15][15];
int N, bgp, rgp, rrp[10], rhp[10], rcp[10], rr, rh, rc;
bool getr;

void bgspace(int bgp)//黑帅活动空间
{
   if(bgp/10-1>0) bspace[bgp/10-1][bgp%10] = 1;
   if(bgp/10+1<4) bspace[bgp/10+1][bgp%10] = 1;
   if(bgp%10-1>3) bspace[bgp/10][bgp%10-1] = 1;
   if(bgp%10+1<7) bspace[bgp/10][bgp%10+1] = 1;
}

void rgspace(int rgp)//红帅控制空间
{
   for(int i = rgp/10-1; i > 0; i--)
    {
        if(!rqp[i][rgp%10]) rspace[i][rgp%10] = 1;
        else {rspace[i][rgp%10] = 1;break;}
    }
}

void rrspace(int ind)//红车控制空间
{
    for(int i = rrp[ind]/10-1; i > 0; i--)
    {
        if(!rqp[i][rrp[ind]%10]) rspace[i][rrp[ind]%10] = 1;
        else  {rspace[i][rrp[ind]%10] = 1;break;}
    }
    for(int i = rrp[ind]/10+1; i < 10; i++)
    {
        if(!rqp[i][rrp[ind]%10]) rspace[i][rrp[ind]%10] = 1;
        else {rspace[i][rrp[ind]%10] = 1;break;}
    }
    for(int i = rrp[ind]%10-1; i > 0; i--)
    {
        if(!rqp[rrp[ind]/10][i]) rspace[rrp[ind]/10][i] = 1;
        else {rspace[rrp[ind]/10][i] = 1;break;}
    }
    for(int i = rrp[ind]%10+1; i < 9; i++)
    {
        if(!rqp[rrp[ind]/10][i]) rspace[rrp[ind]/10][i] = 1;
        else {rspace[rrp[ind]/10][i] = 1;break;}
    }
        #ifdef TESTING
        if(rrp[ind])
        {
            printf("rrp=%d\n", rrp[ind]);
            for(int i = 1; i <= 10; i++)
            {
                for(int j = 1; j <= 9; j++)
                {
                    printf("%2d",rspace[i][j]);
                }
                    printf("\n");
            }

        }
        #endif
}

void rhspace(int ind)//红马控制空间
{
    if(!rqp[rhp[ind]/10-1][rhp[ind]%10])
    {
        if((rhp[ind]/10-2>= 1)&&rhp[ind]%10-1>=1) rspace[rhp[ind]/10-2][rhp[ind]%10-1] = 1;
        if((rhp[ind]/10-2>= 1)&&rhp[ind]%10+1<=9) rspace[rhp[ind]/10-2][rhp[ind]%10+1] = 1;
    }
    if(!rqp[rhp[ind]/10+1][rhp[ind]%10])
    {
        if((rhp[ind]/10+2<= 10)&&rhp[ind]%10-1>=1) rspace[rhp[ind]/10+2][rhp[ind]%10-1] = 1;
        if((rhp[ind]/10+2<= 10)&&rhp[ind]%10+1<=9) rspace[rhp[ind]/10+2][rhp[ind]%10+1] = 1;
    }
    if(!rqp[rhp[ind]/10][rhp[ind]%10-1])
    {
        if((rhp[ind]/10+1<= 10)&&rhp[ind]%10-2>=1) rspace[rhp[ind]/10+1][rhp[ind]%10-2] = 1;
        if((rhp[ind]/10-1>= 1)&&rhp[ind]%10-2>=1) rspace[rhp[ind]/10-1][rhp[ind]%10-2] = 1;
    }
    if(!rqp[rhp[ind]/10][rhp[ind]%10+1])
    {
        if((rhp[ind]/10+1<= 10)&&rhp[ind]%10+2<=9) rspace[rhp[ind]/10+1][rhp[ind]%10+2] = 1;
        if((rhp[ind]/10-1>= 1)&&rhp[ind]%10+2<=9) rspace[rhp[ind]/10-1][rhp[ind]%10+2] = 1;
    }
        #ifdef TESTING
        if(rhp[ind])
        {
            printf("rhp=%d\n", rhp[ind]);
            for(int i = 1; i <= 10; i++)
            {
                for(int j = 1; j <= 9; j++)
                {
                    printf("%2d",rspace[i][j]);
                }
                    printf("\n");
            }

        }
        #endif
}

void rcspace(int ind)//红炮控制空间
{
    bool supported = false;
    for(int i = rcp[ind]/10-1; i > 0; i--)
    {
        if(rqp[i][rcp[ind]%10]&&supported) {rspace[i][rcp[ind]%10] = 1;break;}
        if(rqp[i][rcp[ind]%10]) supported = true;
        if(!rqp[i][rcp[ind]%10]&&supported) rspace[i][rcp[ind]%10] = 1;
    }
    supported = false;
    for(int i = rcp[ind]/10+1; i < 10; i++)
    {
        if(rqp[i][rcp[ind]%10]&&supported) {rspace[i][rcp[ind]%10] = 1;break;}
        if(rqp[i][rcp[ind]%10]) supported = true;
        if(!rqp[i][rcp[ind]%10]&&supported) rspace[i][rcp[ind]%10] = 1;
    }
    supported = false;
    for(int i = rcp[ind]%10-1; i > 0; i--)
    {
        if(rqp[rcp[ind]/10][i] && supported) {rspace[rcp[ind]/10][i] = 1;break;}
        if(rqp[rcp[ind]/10][i]) supported = true;
        if(!rqp[rcp[ind]/10][i] && supported) rspace[rcp[ind]/10][i] = 1;
    }
    supported = false;
    for(int i = rcp[ind]%10+1; i < 9; i++)
    {
        if(rqp[rcp[ind]/10][i] && supported) {rspace[rcp[ind]/10][i] = 1;break;}
        if(rqp[rcp[ind]/10][i]) supported = true;
        if(!rqp[rcp[ind]/10][i] && supported) rspace[rcp[ind]/10][i] = 1;
    }
        #ifdef TESTING
        if(rcp[ind])
        {
            printf("rcp=%d\n", rcp[ind]);
            for(int i = 1; i <= 10; i++)
            {
                for(int j = 1; j <= 9; j++)
                {
                    printf("%2d",rspace[i][j]);
                }
                    printf("\n");
            }

        }
        #endif
        return;
}

void check(char type, int ind)
{
    memset(rspace,0,sizeof(rspace));
    int templ = 0, tempr = 0;
    if(type == 'R')
    {
        templ = rrp[ind]/10;
        tempr = rrp[ind]%10;
    }
    else if(type == 'H')
    {
        templ = rhp[ind]/10;
        tempr = rhp[ind]%10;
    }
    else if(type == 'C')
    {
        templ = rcp[ind]/10;
        tempr = rcp[ind]%10;
    }
    if(templ&&tempr) rqp[templ][tempr] = 0;
    rgspace(rgp);
    for(int i = 0 ; i < 6; i++)
    {
        if(type == 'R')
        {
            if(i != ind&&rrp[i]) rrspace(i);
            if(rhp[i]) rhspace(i);
            if(rcp[i]) rcspace(i);
        }
        else if(type == 'H')
        {
            if(rrp[i]) rrspace(i);
            if(i != ind&&rhp[i]) rhspace(i);
            if(rcp[i]) rcspace(i);
        }
        else if(type == 'C')
        {
            if(rrp[i]) rrspace(i);
            if(rhp[i]) rhspace(i);
            if(i != ind&&rcp[i]) rcspace(i);
        }
    }
    if(type == 'R')
    {
        if(!rspace[rrp[ind]/10][rrp[ind]%10])
            {
                printf("NO\n");
                getr = true;
                #ifdef TESTING
                printf("templ=%d tempr=%d type=%c ind=%d\n", templ, tempr, type, ind);
                for(int i = 1; i <= 10; i++)
                {
                    for(int j = 1; j <= 9; j++)
                    {
                        printf("%2d",rspace[i][j]);
                    }
                        printf("\n");
                }
                #endif
                return ;
            }
    }
    else if(type == 'H')
    {
        if(!rspace[rhp[ind]/10][rhp[ind]%10])
            {
                printf("NO\n");
                getr = true;
                #ifdef TESTING
                printf("templ=%d tempr=%d type=%c ind=%d\n", templ, tempr, type, ind);
                for(int i = 1; i <= 10; i++)
                {
                    for(int j = 1; j <= 9; j++)
                    {
                        printf("%2d",rspace[i][j]);
                    }
                        printf("\n");
                }
                #endif
                return;
            }
    }
    else if(type == 'C')
    {
        if(!rspace[rcp[ind]/10][rcp[ind]%10])
            {
                printf("NO\n");
                getr = true;
                #ifdef TESTING
                printf("templ=%d tempr=%d type=%c ind=%d\n", templ, tempr, type, ind);
                for(int i = 1; i <= 10; i++)
                {
                    for(int j = 1; j <= 9; j++)
                    {
                        printf("%2d",rspace[i][j]);
                    }
                        printf("\n");
                }
                #endif
                return;
            }
    }
    if(templ&&tempr) rqp[templ][tempr] = 1;
    if(type == 'N')
    {
        memset(rspace,0,sizeof(rspace));
        rgspace(rgp);
        for(int i = 0 ; i < 6; i++)
        {
            if(rrp[i]) rrspace(i);
            if(rhp[i]) rhspace(i);
            if(rcp[i]) rcspace(i);
        }
        if(!rspace[ind/10][ind%10])
            {
                printf("NO\n");
                getr = true;
                #ifdef TESTING
                printf("templ=%d tempr=%d type=%c ind=%d\n", templ, tempr, type, ind);
                for(int i = 1; i <= 10; i++)
                {
                    for(int j = 1; j <= 9; j++)
                    {
                        printf("%2d",rspace[i][j]);
                    }
                        printf("\n");
                }
                #endif
                return;
            }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("xt4-1.in","r", stdin);
    freopen("xt4-1.out","w", stdout);
    #endif
    for(;;)
    {
        int templ, tempr;
        getr = false;
        scanf("%d%d%d", &N, &templ, &tempr);
        bgp = templ*10+tempr;
        if(!N) break;
        rr=0,rh=0,rc=0;
        memset(rrp,0,sizeof(rrp));
        memset(rhp,0,sizeof(rhp));
        memset(rcp,0,sizeof(rcp));
        memset(rqp,0,sizeof(rqp));
        memset(rspace,0,sizeof(rspace));
        memset(bspace,0,sizeof(bspace));
        while(N--)
        {
            char temp;
            temp = getchar();
            while(!isalpha(temp)) temp = getchar();
            scanf("%d%d", &templ, &tempr);
            if(temp=='G')
            {
                rgp = templ*10+tempr;
                rqp[templ][tempr] = 1;
            }
            else if(temp=='R')
            {
                rrp[rr]=templ*10+tempr;
                rqp[templ][tempr] = 1;
                rr++;
            }
            else if(temp=='H')
            {
                rhp[rh]=templ*10+tempr;
                rqp[templ][tempr] = 1;
                rh++;
            }
            else if(temp=='C')
            {
                rcp[rc]=templ*10+tempr;
                rqp[templ][tempr] = 1;
                rc++;
            }
        }
        #ifdef TESTING
        printf("N=%d bgp=%d rgp=%d\n", N, bgp, rgp);
        for(int i = 0 ; i < 6; i++) printf("i=%d rrp=%d rhp=%d rcp=%d\n",
                                             i,rrp[i], rhp[i],rcp[i]);
        for(int i = 1; i <= 10; i++)
        {
           for(int j = 1; j <= 9; j++)
            {
                printf("%2d",rqp[i][j]);
            }
            printf("\n");
        }
        #endif
        bgspace(bgp);
        
        for(int i = 1 ; i < 4; i++)
        {
            for(int j = 4 ; j < 7; j++)
            {
                if(bspace[i][j])
                {
                    for(int k = 0; k < 6; k++)
                    {
                        if(rrp[k]||rhp[k]||rcp[k])
                        {
                            if((i*10+j)==rrp[k]) check('R',k);
                            else if((i*10+j)==rhp[k]) check('H',k);
                            else if((i*10+j)==rcp[k]) check('C',k);
                        }
                        if(getr) break;
                    }
                    if(getr) break;
                    check('N',i*10+j);
                }
                if(getr) break;
            }
            if(getr) break;
        }
        if(getr) continue;
        else printf("YES\n");
        #ifdef TESTING
        printf("rgp=%d\n",rgp);
        for(int i = 1; i <= 10; i++)
        {
            for(int j = 1; j <= 9; j++)
            {
                printf("%2d",rspace[i][j]);
            }
                printf("\n");
        }
        #endif
    }
    return 0;
}
