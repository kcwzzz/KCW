using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System;

/*
	created by pokpoongryu

	Collection

	.NET Frameworks는 자료구조를 위한 형식들을 제공한다. 

	바로 사용할 수 있는 컬렉션 클래스 들을 살펴본다. 	


		Array

			모든 배열의 암묵적인 기반 클래스 
			CLR은 배열에 대해 메모리의 연속된 공간을 할당한다. 
			때문에, 색인으로 배열에 접근하는 속도가 아주 빠르다. 
            그러나 일단 생성된 배열의 크기는 변경하지 못한다. 

			배열 자체는 참조 형식이다. 

			Clone()메소드는 얕은 복사shallow copy를 수행한다.
			deep copy는 작성자가 만들어야 한다. 
            
		List<T>
		ArrayList
		//가변배열: 크기를 실행시점에 동적으로 변경할 수 있다. 
		//맨 끝에 요소를 추가하는 것은 효율적이지만 중간에 삽입하는 것은 비효율적이다. 
		//(이름만 List, 헷갈리지 말자. 가변배열이다.)
        
*/

public class Exam_Collection_LIst : MonoBehaviour {

    private static void showArray_0(int tVal)
    {
        Debug.Log(tVal);
    }

    private static bool ContainsA(string tName)
    {
        //'a'가 포함되면 true, 미포함이면 false를 출력

        return tName.Contains("a");
    }


	// Use this for initialization
	void Start ()
    {

        int ti = 0;
        Debug.Log("@@=============");

        //Array

        //배열의 생성과 색인 접근

        //열거

        Debug.Log("@@배열의 열거");
        int[] tArray_0 = { 1, 2, 3, };

        foreach(int tVal in tArray_0)
        {
            Debug.Log(tVal);
        }

        Array.ForEach(tArray_0, showArray_0);

        //길이와 차수


        //검색

        //1차원 배열 안에서 특정 원소들을 찾기 위한 여러 메서드들을 제공하는데 
        //크게 다음 세 부류로 나뉜다. 
        //
        //BinarySearch메서드들
        //IndexOf/LastIndex메서드들
        //Find/FindLast/FindIndex/FindLastIndex/FindAll/Exists/TrueForAll

        Debug.Log("@@검색");

        string[] tNameArray = { "Rodny", "Jack", "Jill" };
        string tMatchString = Array.Find(tNameArray, ContainsA);
        //tNameArray 중에서 containsA를 만족하는 멤버를 찾음.
        //여러개가 있으면 제일 처음에 있는거만 출력됨.
        Debug.Log(tMatchString);

        Debug.Log("@@정렬");

        int[] tNumberArray = { 3, 2, 1 };
        foreach(int tVal in tNumberArray)
        {
            Debug.Log(tVal);

        }

        Array.Sort(tNumberArray);
        foreach(int tVal in tNumberArray)
        {
            Debug.Log(tVal);
        }

        Debug.Log("//@@================");

        //List<T>
        //ArrayList

        List<string> tStringList = new List<string>();

        tStringList.Add("knight");
        tStringList.Add("magician");
        Debug.Log("@");


        for(ti=0; ti<tStringList.Count; ti ++ )
        {
            Debug.Log(tStringList[ti]);

        }

        //paladin druid를 배열에 추가(push back)
        tStringList.AddRange(new[] { "paladin", "druid" });
        //0번째 인덱스에 fighter를 추가
        tStringList.Insert(0, "fighter");
                
        Debug.Log("@");
        for(ti =0; ti<tStringList.Count; ti++)
        {
            Debug.Log(tStringList[ti]);
        }
        
        tStringList.InsertRange(0, new[] { "goblin", "orc" });
        tStringList.Insert(0, "fighter");

        Debug.Log("@");
        for(ti =0; ti < tStringList.Count; ti++)
        {
            Debug.Log(tStringList[ti]);
        }

        tStringList.Remove("kignit");
        tStringList.RemoveAt(3);
        Debug.Log("@==================");

        /*
         Debug.Log("@======");
			for( ti = 0; ti<tStringList.Count; ti++ )
			{
				Debug.Log(tStringList[ti]);
			}

		tStringList.RemoveRange(0,2);	

			Debug.Log("@");
			for( ti = 0; ti<tStringList.Count; ti++ )
			{
				Debug.Log(tStringList[ti]);
			}


		tStringList.RemoveAll( s=>s.StartsWith("f") );

			Debug.Log("@======");
			for( ti = 0; ti<tStringList.Count; ti++ )
			{
				Debug.Log(tStringList[ti]);
			}
            
        
		//ArrayList 는 .NET Framework 1.x코드와의 호환성을 위해 있다. 
		ArrayList tArrayList = new ArrayList();
		tArrayList.Add("hello");
		string tFirst = (string)tArrayList[0];
        */


    }

    // Update is called once per frame
    void Update () {
		
	}
}
