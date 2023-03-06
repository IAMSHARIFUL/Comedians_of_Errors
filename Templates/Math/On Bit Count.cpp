ll bitcount(ll num,int pos)
{
    ll mask=1;
    mask = mask<<pos;
    ll mval = mask&num;
    ll ans;
    if(mval==0)
    {
        ans = num;
        ans = ans>>(pos+1);
        ans = (ans*mask);
    }
    else
    {
        ll tmp = num;
        tmp = tmp>>(pos+1);
        tmp++;
        ans=(tmp*mask);
        tmp=tmp<<(pos+1);
        tmp--;
        tmp=tmp-num;
        ans=ans-tmp;
    }
    return ans;
}
