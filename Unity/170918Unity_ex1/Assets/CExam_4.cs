﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Text;

/*
	created by pokpoongryu

	매개변수

		값으로 전달(복사본) pass by value
		ref수정자 pass by reference
		out수정자 pass by reference, 함수밖으로 나가기 전에는 반드시 배정되어야 한다.
        param수정자 : 마지막 매개변수에만 지정가능하다. 임의의 갯수의 매개변수를 받아들인다.
        
		선택적매개변수( 매개변수 기본값을 얘기한다 )

*/

public class CExam_4 : MonoBehaviour
{
    // Use this for initialization
    void Start()
    {
        int tTemp = 8;
        Doit(tTemp);
        Debug.Log(tTemp);
        
        StringBuilder tSB = new StringBuilder();
        DoitWithString(tSB);
        Debug.Log(tSB);
        
        int tTemp_0 = 8;
        DoitRef(ref tTemp_0);
        Debug.Log(tTemp_0);
        
        string tA = "John";
        string tB = "Elza";

        DoSwap(tA, tB);
        Debug.Log(tA + ", " + tB);

        DoSwapRef(ref tA, ref tB);
        Debug.Log(tA + ", " + tB);







        string tResultA = "";
        string tResultB = "";

        DoSplit("Pok Poong Ryu", out tResultA, out tResultB);
        Debug.Log(tResultA);
        Debug.Log(tResultB);






        int tTotalSum = DoSum(1, 2, 3, 4);
        Debug.Log(tTotalSum);
        //배열 사용도 가능.
        Debug.Log(DoSum(new int[] { 1, 2, 3, 4 }));



        DoPrint();
        DoPrint(898);

    }

    // Update is called once per frame
    void Update()
    {

    }


    //기본적으로 매개변수는 값으로 전달( 복사 )
    public void Doit(int tA)
    {
        tA = tA + 1;

        Debug.Log(tA);
    }

    //기본적으로 매개변수는 값으로 전달( 복사 )
    //참조 형식의 매개변수이면 참조의 복사본이 전달
    public void DoitWithString(StringBuilder tSB)
    {
        tSB.Append("test");

        tSB = null;
    }


    //ref수정자 참조로 전달
    public void DoitRef(ref int tVal)
    {
        tVal = tVal + 1;

        Debug.Log(tVal);
    }



    public void DoSwap(string tA, string tB)
    {
        string tTemp = tA;
        tA = tB;
        tB = tTemp;
    }

    public void DoSwapRef(ref string tA, ref string tB)
    {
        string tTemp = tA;
        tA = tB;
        tB = tTemp;
    }




    //out수정자
    public void DoSplit(string tName, out string tFirstName, out string tLastName)
    {
        int tIndex = tName.LastIndexOf(' ');
        //out수정자가 적용된 매개변수에 값이 설정되지 않으면 컴파일 에러를 낸다. 
        tFirstName = tName.Substring(0, tIndex);
        tLastName = tName.Substring(tIndex + 1);
    }


    //param수정자
    public int DoSum(params int[] tIntArray)
    {
        int tResult = 0;

        int ti = 0;

        for (ti = 0; ti < tIntArray.Length; ti++)
        {
            tResult += tIntArray[ti];
        }

        return tResult;
    }


    //선택적매개변수: 선택적 매개변수에는 ref, out수정자를 적용할 수 없다.
    public void DoPrint(int tVal = 777)
    {
        Debug.Log("DoPrint " + tVal);
    }
}