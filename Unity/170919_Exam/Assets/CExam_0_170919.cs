using System.Collections;
using System.Collections.Generic;
using UnityEngine;
/*

	created by pokpoongryu

	https://docs.microsoft.com/ko-kr/dotnet/csharp/programming-guide/classes-and-structs/using-structs

	struct vs class 

		C#에서는 struct와 class가 다음과 같이 서로 다르다. 

		1) struct는 값 형식이고, class는 참조 형식이다. 
		2) struct는 상속을 지원하지 않는다.( 다만, System.ValueType을 상속받기는 한다.)
*/


public struct SUnitInfo
{
    //struct에서는 멤버변수 초기화가 안됨.
    //public int mX = 0;
    public int mX;
    public int mY;

    //struct는 매개변수 없는 생성자를 가질 수 없음.
    //public SUnitInfio()
    //{
    //}

    public SUnitInfo(int tX, int tY)
    {
        this.mX = tX;
        this.mY = tY;
    }
}

/*
public struct SActorInfo : SUnitInfio
{

}
*/

public class CExam_0_170919 : MonoBehaviour
{

    /*
    new 연산자를 사용하여 구조체 개체를 생성할 경우 
    구조체 개체가 생성된 후에 적절한 생성자가 호출됩니다. 
    
        클래스와 달리 구조체는 new 연산자를 사용하지 않고 인스턴스화할 수 있습니다.
    이런 경우에는 생성자를 호출하지 않으므로 할당이 더 효율적으로 이루어집니다. 

    하지만 필드가 할당되지 않은 상태로 남아 있게 되며 개체를 
    사용하려면 모든 필드를 초기화해야 합니다.
    */

    // Use this for initialization
    void Start()
    {
        /*
        값타입이라서  에러 발생
        SUnitInfio tInfo_0;
        tInfo_0.mX = 100;
        tInfo_0.mY = 100;
        */

        //Struct를 써도 동적할당할 수 있다.
        //근데 이럴바에는 class로 쓰는게 낫다.
        SUnitInfo tInfo_0 = new SUnitInfo();
        SUnitInfo tInfo_1 = new SUnitInfo(200,200);

        Debug.Log("tInfo_0  : " + tInfo_0.mX.ToString() + "," + tInfo_0.mY.ToString());
        Debug.Log("tInfo_1  : " + tInfo_1.mX.ToString() + "," + tInfo_1.mY.ToString());
    }

    // Update is called once per frame
    void Update()
    {

    }
}
