import numpy as np
import random

# Define environment parameters
n_states = 5            # Number of states (simple line world)
n_actions = 2           # Actions: 0 = left, 1 = right
q_table = np.zeros((n_states, n_actions))

# Hyperparameters
alpha = 0.1             # Learning rate
gamma = 0.9             # Discount factor
epsilon = 1             # Exploration rate
#n_episodes = 5         # Number of episodes

# Reward function
def get_reward(state):
    return 1 if state == n_states - 1 else 0

# Epsilon-greedy action selection
def choose_action(state):
    if random.uniform(0, 1) < epsilon:
        return random.choice([0, 1])  # Explore
    return np.argmax(q_table[state])  # Exploit

# State transition logic
def take_action(state, action):
    if action == 0:  # Left
        return max(0, state - 1)
    else:  # Right
        return min(n_states - 1, state + 1)

def update_epsilon(eps):
    global epsilon
    epsilon = max(0.01, eps * 0.995)
    #print(f"updated epsilon: {epsilon}")

n_episodes = 50000        # Number of episodes
# Training SARSA
for episode in range(n_episodes):
    state = 0
    action = choose_action(state)
    update_epsilon(epsilon)
    while state != n_states - 1:
        next_state = take_action(state, action)
        reward = get_reward(next_state)
        next_action = choose_action(next_state)
        #print(f'state: {state}, action: {action}, reward: {reward}, epsilon: {epsilon}')
        # SARSA update rule
        q_table[state, action] += alpha * (
            reward + gamma * q_table[next_state, next_action] - q_table[state, action]
        )
        #print("updated q_table")
        #print(q_table)
        #print("=====================")
        # Move to the next step
        state = next_state
        action = next_action

# Display learned Q-table
print("Learned Q-table:")
print(q_table)

#if __name__ == "__main__":
#    main()

# TODO: ask this
# yesterday we talked about SARSA algorithm. the code you gave me has this lines:
# "print("Learned Q-table:")
#  61 print(q_table"
# What does the learned q-table represent after the training sarsa loop is done?
