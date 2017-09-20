using System.Collections;
using System.Collections.Generic;
using UnityEngine;


/*

	created by pokpoongryu

	LinkedList<T>

		더블 링크드리스트로 구현된다.

*/

public class InstExam_LinkedList : MonoBehaviour {

	// Use this for initialization
	void Start ()
    {
        Debug.Log("@LinkedList 를 살펴본다");
        LinkedList<string> tStringLinkedList = new LinkedList<string>();

        tStringLinkedList.AddFirst("도");
        tStringLinkedList.AddLast("솔");

        //색인 연산을 지원하지 않음.
        /*
        Debug.Log("@=======");
        for (int ti =0; ti<tStringLinkedList.Count; ti++)
        {
            Debug.Log(tStringLinkedList[ti]);
        }
        */
        //foreach 열거자
        Debug.Log("@=======");
        foreach(string tString in tStringLinkedList)
        {
            Debug.Log(tString);
        }

        //맨 처음
        tStringLinkedList.AddAfter(tStringLinkedList.First, "레");

        //첫 번째 다음.
        tStringLinkedList.AddAfter(tStringLinkedList.First.Next, "mi");

        //맨 마지막
        tStringLinkedList.AddAfter(tStringLinkedList.Last, "fa");

        Debug.Log("@=============");
        foreach(string tSring in tStringLinkedList)
        {
            Debug.Log(tSring);
        }

        //삭제하기
        tStringLinkedList.RemoveFirst();
        tStringLinkedList.RemoveLast();

        Debug.Log("@=============");
        foreach (string tSring in tStringLinkedList)
        {
            Debug.Log(tSring);
        }


        LinkedListNode<string> tNode = tStringLinkedList.Find("mi");

        if(null != tNode)
        {
            tStringLinkedList.Remove(tNode);
            tStringLinkedList.AddFirst(tNode);
            
        }

        Debug.Log("@@@");
        
        foreach (string tSring in tStringLinkedList)
        {
            Debug.Log(tSring);
        }
    }

    // Update is called once per frame
    void Update () {
		
	}
}
