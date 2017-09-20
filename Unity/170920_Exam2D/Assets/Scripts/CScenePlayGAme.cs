using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CScenePlayGAme : MonoBehaviour {

    //instance

    public CAlberto mpAlberto = null;
    public CUIPlayGame mpUIPlayGame= null;
    
	// Use this for initialization
	void Start ()
    {
        mpUIPlayGame.SetScene(this);
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
