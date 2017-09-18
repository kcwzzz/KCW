using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CUISceneTest : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    public void OnClickBtnTest()
    {
        Debug.Log("CUISceneTest.onClickBtnTest");

        int tResult = 0;
        tResult= Random.Range(1, 6+1);
        Debug.Log(tResult);
    }

}
