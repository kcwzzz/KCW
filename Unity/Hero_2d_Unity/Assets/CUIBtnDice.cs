using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CUIBtnDice : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    public void OnClickBtnDice()
    {
        Debug.Log("Dice Roll");

        int tResult = 0;
        tResult = Random.Range(1, 7);
        Debug.Log(tResult);
    }
}