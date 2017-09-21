using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CDxGameOver : MonoBehaviour
{

    // Use this for initialization
    void Start()
    {
        this.Hide();
    }

    // Update is called once per frame
    void Update()
    {

    }

    public bool IsShow()
    {
        return this.gameObject.activeInHierarchy;
    }

    public void show()
    {   
        this.gameObject.SetActive(true);
    }

    public void Hide()
    {
        this.gameObject.SetActive(false);
    }

    public void OnClickBtnRetry()
    {
        this.Hide();
    }
}
