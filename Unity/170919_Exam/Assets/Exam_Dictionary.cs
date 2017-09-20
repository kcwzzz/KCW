using System.Collections;
using System.Collections.Generic;
using UnityEngine;
//typeof: https://docs.microsoft.com/ko-kr/dotnet/csharp/language-reference/keywords/typeof

//C#은 '리플렉션'이란 기능을 제공한다. 
//실행중에 타입에 대한 여러 정보를 조회할 수 있는 기능이다.
//이것이 가능한 이유는 CLR이 존재하기 때문이다.

//
//for MethodInfo

using System.Reflection;

/*
	created by pokpoongryu


	dictionary

	각 원소가 키-값 쌍인 컬렉션으로 주된 용도는 조회와 정렬된 목록이다. 
	dictionary중에서 'dictionary'와 '정렬된 dictionary'만 살펴본다.

	1) Dictionary

		해쉬테이블로 구현된다.

		중복된 키는 허용하지 않는다. 
		정렬되지 않는다. 
		항목 순서가 항목을 추가한 순서와 다르다.

	2) 정렬된 Dictionary
        //균형 이진 트리
		중복된 키는 허용하지 않는다. 
		항상 정렬된 상태로 존재한다.(삽입시 정렬이 일어난다)

			SortedList<TKey, TValue>		: 배열 두 개로 구현된다.
			SortedDictionary<TKey, TValue>	: 트리로 구현된다.

	
*/

public class Exam_Dictionary : MonoBehaviour
{

    // Use this for initialization
    void Start()
    {
        Debug.Log("@==========Dictionary");

        Dictionary<string, int> tDictionary = new Dictionary<string, int>();

        tDictionary.Add("One", 1);
        tDictionary["Two"] = 2;
        tDictionary["Two"] = 22;//같은 키값을 입력하면 새 값으로 갱신한다.

        tDictionary["Three"] = 3;
        tDictionary["four"] = 3;

        Debug.Log(tDictionary["Two"]);
        Debug.Log(tDictionary.ContainsKey("One"));  //키값 검색은 빠름
        Debug.Log(tDictionary.ContainsValue(3));  //키값 검색은 빠름

        Debug.Log(tDictionary.ContainsKey("onE"));  //없는 값은 false


        //나열하기
        foreach (string tString in tDictionary.Keys)
        {
            Debug.Log(tString);
        }

        foreach (int tVal in tDictionary.Values)
        {
            Debug.Log(tVal.ToString());
        }

        foreach (KeyValuePair<string, int> tKVP in tDictionary)
        {
            Debug.Log(tKVP.Key + " : " + tKVP.Value);
        }

        Debug.Log("@=====SortedList");
        //var 은 C++로 치자면 auto키워드와 같다. 타입을 추론한다.
        //var tSortedList = new SortedList<string, MethodInfo>();

        SortedList<string, MethodInfo> tSOrtedList = new SortedList<string, MethodInfo>();

        foreach (MethodInfo tInfo in typeof(object).GetMethods())
        {
            //tSortedList.Add( tInfo.Name, tInfo); //이것은 예외를 일으킨다. 왜냐하면 중복된 내용을 처리하지 못하기 때문이다.
            tSOrtedList[tInfo.Name] = tInfo;
        }

        foreach (string tName in tSOrtedList.Keys)
        {
            Debug.Log(tName);
        }

        foreach (MethodInfo tInfo in tSOrtedList.Values)
        {
            Debug.Log(tInfo.Name + "의 반환 형식은 " + tInfo.ReturnType);
        }

        Debug.Log("@===============SortedDictionary");

        SortedDictionary<string, MethodInfo> tSortedDIctionary = new SortedDictionary<string, MethodInfo>();
        foreach (MethodInfo tInfo in typeof(object).GetMethods())
        {
            //tSortedDictionary.Add( tInfo.Name, tInfo); //이것은 예외를 일으킨다. 왜냐하면 중복된 내용을 처리하지 못하기 때문이다.

            tSortedDIctionary[tInfo.Name] = tInfo;//이 것은 중복 내용이있으면 갱신한다.
        }
        foreach (string tName in tSortedDIctionary.Keys)
        {
            Debug.Log(tName);
        }

        foreach (MethodInfo tInfo in tSortedDIctionary.Values)
        {
            Debug.Log(tInfo.Name + "의 반환 형식은 " + tInfo.ReturnType);
        }
    }   

    // Update is called once per frame
    void Update()
    {

    }
}

/*
 * 대괄호 안의 값이 배열은 "Index" 이고 Dictionary는 "키값"이다.
 * 
 */
