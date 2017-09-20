using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/*
	created by pokpoongryu
	Queue<T>
	Queue

	Stack<T>
	Stack

	BitArray

		bool값 하나에 비트 하나만 사용하므로, 
		각 값을 1바이트에 저장하는 보통의 bool배열이나 bool형식의 제네릭List보다 메모리를 효율적으로 사용한다. 
*/

public class Exam_Stack_Queue_BitArray : MonoBehaviour {

	// Use this for initialization
	void Start ()
    {
        Debug.Log("@@@Queue");

        Queue<int> tQueue = new Queue<int>();

        tQueue.Enqueue(10);
        tQueue.Enqueue(20);

        int[] tData = tQueue.ToArray();
        //요소를 배여로 복하, Queue는 꺼내어 보지 않는한 자체 조회가 되지 않으므로.

        Debug.Log(tQueue.Count);
        Debug.Log(tQueue.Peek());
        //Peek 는 내용을 빼지말고 값만 출력
        Debug.Log(tQueue.Dequeue());
        //Debug.Log(tQueue.Dequeue());
        //Debug.Log(tQueue.Dequeue());
        //Pop.Dequeue 는 노드 이상을 진행하면 에러남.

        Debug.Log("@@@Stack");

        Stack<int> tStack = new Stack<int>();
        tStack.Push(1);
        tStack.Push(2);
        tStack.Push(3);
        Debug.Log(tStack.Count);
        Debug.Log(tStack.Peek());
        Debug.Log(tStack.Pop());
        Debug.Log(tStack.Pop());
        Debug.Log(tStack.Pop());
        //Debug.Log(tStack.Pop());//이것은 에러.



        /*


        BitArray tBitArray = new BitArray(2);
        tBitArray[1] = true;


        Debug.Log("@@@BitArray");
        foreach (bool tIs in tBitArray)
        {
            Debug.Log(tIs);
        }

        //tBitArray.Or(tBitArray);
        //tBitArray.And(tBitArray);
        tBitArray.Xor(tBitArray);

        Debug.Log("@@@BitArray");
        foreach (bool tIs in tBitArray)
        {
            Debug.Log(tIs);
        }

    */
    }

    // Update is called once per frame
    void Update () {
		
	}
}
/*
 * ToArray  요소들을 배열로 복사해서 조회할 수 있도록 한다.
 * Pop. Dequeue 는 노드 이상을 진행하면 에러남.
 * 
 * 
 * 
 */