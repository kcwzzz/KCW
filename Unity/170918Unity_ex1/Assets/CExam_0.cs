using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CExam_0 : MonoBehaviour
{

    //MonoBehaviour는 object에 붙이려면 상속받아야 한다.

    // Use this for initialization
    void Start()
    {
        Debug.Log("Hello World");
        //unity에서 제공하는 클래스 -> 유니티 콘솔창에 뜸

        char[] tVowels = null;
        tVowels = new char[5];

        int ti = 0;
        for (ti = 0; ti < 5; ti++)
        {
            Debug.Log(tVowels[ti]);
        }

        tVowels[0] = 'a';
        tVowels[1] = 'e';
        tVowels[2] = 'i';
        tVowels[3] = 'o';
        tVowels[4] = 'u';

        Debug.Log(tVowels[1]);

        //int ti = 0;
        for (ti = 0; ti < 5; ti++)
        {
            Debug.Log(tVowels[ti]);
        }


        for (ti = 0; ti < tVowels.Length; ti++)
        {
            Debug.Log(tVowels[ti]);
        }

        Debug.Log("@tVowels 0");

        char[] tVowels_0 = { 'a', 'e', 'i', 'o', 'u' };

        for(ti =0; ti<tVowels_0.Length; ti ++ )
        {
            Debug.Log(tVowels_0[ti]);
        }

        Debug.Log("@");

        int[] tArray = null;
        tArray = new int[1000];
        Debug.Log(tArray[123]);
        //C#은 초기화하지않아도 기본값으로 들어가있다.
        //int 는 0이고 char는 ''과 같은 식으로 기본값으로 초기화 된다. 
    }

    // Update is called once per frame
    void Update()
    {

    }
}