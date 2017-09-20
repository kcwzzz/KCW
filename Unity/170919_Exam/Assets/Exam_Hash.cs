using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//for SortedSet
//using System;

/*
	created by pokpoongryu


	C++과 다르게 중복을 허용하지 않는다.


	HashSet<T> :정렬하지 않는다. 
		
    SortedSet<T>: 이것은 아직 유니티에서는 사용불가이다. 정렬한다.


	Contains 메소드는 해시 기반 조회(hash_based lookup)를 이용해서 빠르게 실행된다. 
	중복된 원소를 저장하지 않으며 중복된 원소를 추가하는 요청은 무시한다. 
	색인으로 특정 원소에 접근할 수 없다. 

	HashSet<T>는 키들만 저장하는 해시테이블로 구현된다.
	

	집합연산
*/

public class Exam_Hash : MonoBehaviour {
    
	// Use this for initialization
	void Start ()
    {
        Debug.Log("@@HashSet 중복을 허용하지 않는다. 정렬하지 않는다.");

        var tLettersHashSet_0 = new HashSet<char>("the quick brown fox");
        //thr quickbrownfx <- 실재 출력될 값
        //스페이스바, o는 중복이기 때문에 출력되지 않음.

        Debug.Log(tLettersHashSet_0.Contains('t'));
        Debug.Log(tLettersHashSet_0.Contains('j'));
        //t는 포함되어 있고 j는 포함되어있지 않음.

        foreach (char tC in tLettersHashSet_0)
        {
            Debug.Log(tC);

        }

        Debug.Log("@@ z를 추가해봄");

        tLettersHashSet_0.Add('z');
        tLettersHashSet_0.Add('z');

        foreach(char tC in tLettersHashSet_0)
        {
            Debug.Log(tC);
        }

        Debug.Log("@@집합연산 IntersectWith  교차되는 것들을 선별한다.");
        //모음만 남기기

        var tLettersHashSet_1 = new HashSet<char>("the quick brown fox");
        tLettersHashSet_1.IntersectWith("aeiou");

        foreach(char tC in tLettersHashSet_1)
        {
            Debug.Log(tC);
        }


        Debug.Log("@@집합연산 ExceptWith 해당하는 것들을 제외한다.");
        var tLettersHashSet_2 = new HashSet<char>("the quick brown fox");
        tLettersHashSet_2.ExceptWith("aeiou");

        foreach (char tC in tLettersHashSet_2)
        {
            Debug.Log(tC);
        }

        Debug.Log("@@집합연산 SymmetricExceptWith 두 집합 모두에 존재하지 않는 것들만 남긴다.");
        var tLettersHashSet_3 = new HashSet<char>("the quick brown fox");

        //tLettersHashSet_3.SymmetricExceptWith("the lazy brown fox");
        //<-원래 작동하면 안됨 스페이스바때문에 안되는게 정상

        tLettersHashSet_3.SymmetricExceptWith("the lazy");

        foreach (char tC in tLettersHashSet_3)
        {
            Debug.Log(tC);
        }

        Debug.Log("System.Environment.Version: " + System.Environment.Version);

        //Unity 5.0은 .NET Framework 2.0기반이고 일부 3.5를 지원한다.HashSet
        //SortedSet은 .NET Framework 4.0부터 사용가능하다.
        /* 
		Debug.Log("@@SortedSet");

		var tLettersSortedSet = new SortedSet<char>("the quick brown fox");

		foreach( char tC in tLettersSortedSet)
		{
			Debug.Log(tC);
		}
		*/

    }


    // Update is called once per frame
    void Update () {
		
	}
}

/*
 * InterSectWith는 교차되는 것을 선별(AND 연산)
 * ExceptWith
 * 
 * */