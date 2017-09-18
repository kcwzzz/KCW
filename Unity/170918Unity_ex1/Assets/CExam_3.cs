using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Text;

/*
	created by pokpoongryu

	스택과 힙메모리

		스택에는 지역변수, 매개변수 등이 담긴다.

		힙에는 참조형식의 인스턴스들이 저장된다.
		C#에서는 명시적으로 메모리를 해지할 수 없으며 
			참조되지 않는 객체는 자동수거된다.
		정적필드도 힙에 저장된다.


	확정배정 define assignment policy

		반드시 초기화하는 정책

		지역변수의 값을 읽으려면, 그 전에 반드시 어떤 값이 변수에 배정되어 있어야만 한다.
		메서드를 호출할 때 함수 인수들을 반드시 지정해야 한다.
		그 외에 모든 변수(필드나 배열 원소)는 런타임이 자동으로 초기화한다.
*/

public class CExam_3 : MonoBehaviour {
    
    int mVal;
   	// Use this for initialization
	void Start ()
    {
        int tResult = 0;
        tResult = DoFactorial(8);

        Debug.Log(tResult.ToString());

        StringBuilder tRef_0 = new StringBuilder("object1");
        Debug.Log(tRef_0);

        StringBuilder tRef_1 = new StringBuilder("object2");
        StringBuilder tRef_2 = tRef_1;
        Debug.Log(tRef_2);

        //초기화되지 않은 변수라 컴파일 시점에 에러남
        //int tTemp;
        //Debug.Log(tTemp);

        //배열은 런타임이 자동으로 초기화할 것이므로 컴파일 시점에 에러나지 않는다.
        int[] tIntArray = new int[1];
        Debug.Log(tIntArray[0]);

        //필드는 런타임이 자동으로 초기화할 것이므로 컴파일 시점에 에러나지 않는다.
        Debug.Log(mVal);

    }

    // Update is called once per frame
    void Update () {
		
	}

    int DoFactorial(int tVal)
    {
        int tResult = 0;
        if(0==tVal)
        {
            return 1;
        }
        else
        {
            tResult = tVal * DoFactorial(tVal - 1);
        }
        return tResult;

    }

}