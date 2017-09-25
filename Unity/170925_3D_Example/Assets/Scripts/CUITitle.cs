using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;

public class CUITitle : MonoBehaviour
{

    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }

    public void OnClickBtnGoScenePlayGame()
    {
        SceneManager.LoadScene("CScenePlayGame");
        //SceneManager.LoadScene("CSceneGrid_0", LoadSceneMode.Additive);
        SceneManager.LoadScene("CSceneGrid_0", LoadSceneMode.Additive);
        SceneManager.LoadScene("CScenePlayGameUI", LoadSceneMode.Additive);

    }
}
