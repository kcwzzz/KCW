using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/*

	created by pokpoongryu





	delegate

		임의의 메서드를 호출하는 방법을 담은 객체이다. 
		( 콜하는 측과 콜받는 측의 결합을 끊을 수 있게 된다. )


		deleagte 변수에 메서드를 배정하는 연산은 실행시점에 일어난다. 

	다중캐스트대리자 multicast delegate

		여러 개의 메서드를 대상으로 할 수 있다. 

*/

public class CUnit
{
    public int mX = 0;
    public int mY = 0;
    public int Doit(int tA)
    {
        Debug.Log("CUnit.Doit" + tA.ToString());

        return 0;
    }
}

public class Exam_delegate : MonoBehaviour
{
    delegate int CCallFunc(int tA);
    delegate void CCallExamMultiCast();

    // Use this for initialization
    void Start()
    {
        Debug.Log("@@=========");

        int tResult = 0;
        tResult = DoSquare(3);

        Debug.Log(tResult);

        CCallFunc tCallFunc = DoSquare;
        //CCallFunc tCallFunc = new CCallFunc(DoSquare);

        tResult = tCallFunc.Invoke(4);
        Debug.Log(tResult);

        //tResult = tCallFunc.Invoke(4);
        //Debug.Log(tResult);

        CCallExamMultiCast tCall = null;
        tCall += InputControl;
        tCall += DisplayToConsole;
        tCall += SaveToFile;

        tCall();

        tCall -= DisplayToConsole;
        tCall();

        CUnit tUnit = new CUnit();
        CCallFunc tUnitCallFunc = tUnit.Doit;
        tUnitCallFunc(777);

    }

    // Update is called once per frame
    void Update()
    {

    }

    int DoSquare(int tA)
    {
        int tResult = 0;

        tResult = tA * tA;

        return tResult;
    }

    void InputControl()
    {
        Debug.Log("InputControl");

    }

    void DisplayToConsole()
    {
        Debug.Log("DisplayToConsole");
    }

    void SaveToFile()
    {
        Debug.Log("SaveToFile");
    }


}
