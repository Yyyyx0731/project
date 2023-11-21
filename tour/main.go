package main

import (
	"github.com/golang/program/travel_study/tour/cmd"
	"log"
)

func main() {
	err := cmd.Execute()
	if err != nil {
		log.Fatalf("cmd.Execute err:%v",err)
	}
}
