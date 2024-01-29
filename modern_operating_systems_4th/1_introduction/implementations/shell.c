#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/wait.h>

#define PROMPT '$'
#define STARTLEN 256

#define LOG(text) \
        do{printf("[INFO] %s\n", text);}\
        while(0)
#define LOG_TOKENS(tokens, token_count) \
        do{\
        for(size_t i = 0; i < token_count; i++) printf("[DBUG]Token %s\n", tokens[i]);\
        }\
        while(0)

size_t create_prompt(size_t* malloc_size, char** input){
  putchar(PROMPT);
  int read_c = getline(input, malloc_size, stdin);
  return read_c;
}

size_t parse_input(char* input, char** tokens){
  size_t len = strlen(input);
  size_t token_count = 0;
  uint8_t start, quote = 0;
  for (size_t i = 0; i < len; i++) {
    char c = input[i];
    if(c < 33 && !quote){
      input[i] = '\0';
      start = 0;
      continue;
    }
    if(c == '"'){
      if (!quote){ 
        start = 1;
        tokens[token_count] = &input[i];
        token_count++;
      }
      quote = !quote;
      continue;
    }
    if(!start){
      start = 1;
      tokens[token_count] = &input[i];
      token_count++;
    }
  }
  return token_count;
}

size_t run_command(char **tokens, size_t token_count){
  int link[2];
  pid_t pid = fork();
  int status = 0;
  int background = 0;
  char* last = tokens[token_count-1]; 
  if (!strcmp(last, "&") || last[strlen(last)] == '&'){
    background = 1;
    tokens[token_count-1]='\0';
    token_count--;
    char str[256];
    sprintf(str, "Runnning %s as background process with PID: %d", tokens[0], pid);
    LOG(str);
  }
  tokens[token_count] = NULL;
  
  if(pid != 0){
    if (!background){
      waitpid(-1, &status, 0);
    }
  }else{
    execvp(tokens[0], tokens); 
  }

  return 0; 
}

int main(int argc, char *argv[]){
  size_t malloc_size = STARTLEN * sizeof(char);
  char* input = (char *) malloc(malloc_size);
  char* tokens[STARTLEN];
  size_t len = 0;
  size_t token_count = 0;
  

  while(1){
    len = create_prompt(&malloc_size, &input);
    token_count = parse_input(input, tokens);
    run_command(tokens, token_count);
    token_count = 0;
  }
  free(input);
  return EXIT_SUCCESS;
}
