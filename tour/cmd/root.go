package cmd

import "github.com/spf13/cobra"

var rootCmd = &cobra.Command{
	Use: "",
	Short: "",
	Long: "",
}

func Execute() error {
	return rootCmd.Execute()
}

func init() {
	//每一个子命令都需要到rootCmd中进行注册，否则无法使用
	rootCmd.AddCommand(wordCmd)
	rootCmd.AddCommand(timeCmd)
	rootCmd.AddCommand(sqlCmd)
}