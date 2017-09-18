using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public struct SPoint
{
    //값 타입은 초기화가 안됨.
    public int mX;// =0; 
    public int mY;
}

public class CNewPoint
{
    public int mX = 0;
    public int mY = 0;
}

public class CExam_1 : MonoBehaviour
{

    // Use this for initialization
    void Start()
    {
        Debug.Log("배열");
        Debug.Log("값 형식 vs 참조 형식");


        int ti = 0;

        SPoint[] tPointArray_0 = null;
        tPointArray_0 = new SPoint[1000];

        for (ti = 0; ti < tPointArray_0.Length; ti++)
        {
            //값 형식은 별도 동적할당은 필요없음.
            tPointArray_0[ti].mX = ti;
            tPointArray_0[ti].mY = ti;
        }

        Debug.Log(tPointArray_0[776].mX.ToString());
        Debug.Log(tPointArray_0[776].mY.ToString());

        CNewPoint[] tPointArray_1 = null;
        tPointArray_1 = new CNewPoint[1000];

        for(ti =0; ti < tPointArray_1.Length; ti++ )
        {
            //참조형식은 new로 동적할당을 해줘야 함.
            tPointArray_1[ti] = new CNewPoint();

            tPointArray_1[ti].mX = ti;
            tPointArray_1[ti].mY = ti;
        }

        Debug.Log(tPointArray_1[776].mX.ToString());
        Debug.Log(tPointArray_1[776].mY.ToString());
    }

    // Update is called once per frame
    void Update()
    {

    }
}
